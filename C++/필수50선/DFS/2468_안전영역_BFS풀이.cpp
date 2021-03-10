#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V vector
struct L { int y, x; };

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    V<V<int>> map(N, V<int>(N));
    int mh = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
            mh = max(mh, map[i][j]); 
        }
    int r = 1;
    int dy[] = {0, 0, -1, 1};
    int dx[] = {-1, 1, 0, 0};
    for (int h=1; h<mh; h++) {
        int _r = 0;
        V<V<bool>> visited(N, V<bool>(N));
        for (int y=0; y<N; y++)
            for (int x=0; x<N; x++) {
                if (map[y][x] > h && !visited[y][x]) {
                    queue<L> q;
                    q.push({y, x}); visited[y][x] = 1;
                    while (!q.empty()) {
                        L l = q.front(); q.pop();
                        for (int i=0; i<4; i++) {
                            int ny = l.y+dy[i], nx = l.x+dx[i];
                            if (ny < 0 || N <= ny || nx < 0 || N <= nx)
                                continue;
                            if (map[ny][nx] > h && !visited[ny][nx]) {
                                q.push({ny, nx});
                                visited[ny][nx] = 1;
                            }
                        }
                    }
                    _r++;
                }
            }
        r = max(r, _r);
    }
    cout << r;
    return 0;
}