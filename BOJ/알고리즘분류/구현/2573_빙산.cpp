#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V vector
struct L { int y, x; };

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    V<V<V<int>>> m(N, V<V<int>>(M, V<int>(2)));
    V<V<bool>> visited(N, V<bool>(M));
    for (int y=0; y<N; y++) for (int x=0; x<M; x++) cin >> m[y][x][0];
    int cnt = 0;
    while (1) {
        queue<L> q;
        fill(visited.begin(), visited.end(), V<bool>(M, 0));
        bool f = 0;
        for (int y=0; y<N; y++) for (int x=0; x<M; x++) {
            if (m[y][x][0] && !visited[y][x]) {
                if (f) { cout << cnt; return 0; }
                visited[y][x] = 1; f = 1;
                q.push({y, x});
                while (!q.empty()) {
                    L l = q.front(); q.pop();
                    for (int i=0; i<4; i++) {
                        int ny = l.y+dy[i], nx = l.x+dx[i];
                        if (ny < 0 || N <= ny || nx < 0 || M <= nx || visited[ny][nx])
                            continue;
                        if (m[ny][nx][0]) {
                            q.push({ny, nx}); visited[ny][nx] = 1;
                        }
                        else m[l.y][l.x][1]++;
                    }
                }
            }
        }
        if (!f) { cout << 0; break; }
        for (int y=0; y<N; y++) for (int x=0; x<M; x++) {
            m[y][x][0] -= min(m[y][x][0], m[y][x][1]);
            m[y][x][1] = 0;
        }
        cnt++;
    }
    return 0;
}