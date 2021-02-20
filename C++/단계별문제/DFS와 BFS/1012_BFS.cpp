#include <iostream>
#include <queue>
using namespace std;
struct L {
    int y, x;
};

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int M, N, K, x, y;
        cin >> M >> N >> K;
        int m[50][50] = { 0, };
        bool visited[50][50] = { 0, };
        queue<L> q;
        while (K--) {
            cin >> x >> y;
            m[y][x] = 1;
        }
        int r = 0;
        for (y=0; y<N; y++) {
            for (x=0; x<M; x++) {
                if (!m[y][x] || visited[y][x]) continue;
                q.push({y, x});
                while (!q.empty()) {
                    L l = q.front(); q.pop();
                    for (int k=0; k<4; k++) {
                        int ny = l.y+dy[k], nx = l.x+dx[k];
                        if (0 <= ny && ny < N && 0 <= nx && nx < M && m[ny][nx] && !visited[ny][nx]) {
                            q.push({ny, nx});
                            visited[ny][nx] = 1;
                        }
                    }
                }
                r++;
            }
        }
        cout << r << "\n";
    }
    return 0;
}