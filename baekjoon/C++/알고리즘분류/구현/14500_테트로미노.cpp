#include <iostream>
using namespace std;

int N, M;
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
int m[500][500];
bool visited[500][500];
int ans = 0;

void dfs(int d, int s, int y, int x) {
    s += m[y][x];
    if (d == 4) {
        ans = max(ans, s);
        return;
    }
    visited[y][x] = 1;
    for (int i=0; i<4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx])
            dfs(d+1, s, ny, nx);
    }
    visited[y][x] = 0;
}

void verify(int y, int x) {
    if (x && x < M-1) {
        int hs = m[y][x-1]+m[y][x]+m[y][x+1];
        if (y) ans = max(ans, hs+m[y-1][x]);
        if (y < N-1) ans = max(ans, hs+m[y+1][x]);
    }
    if (y && y < N-1) {
        int vs = m[y-1][x]+m[y][x]+m[y+1][x];
        if (x) ans = max(ans, vs+m[y][x-1]);
        if (x < M-1) ans = max(ans, vs+m[y][x+1]);
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int y=0; y<N; y++)
        for (int x=0; x<M; x++)
            cin >> m[y][x];
    for (int y=0; y<N; y++)
        for (int x=0; x<M; x++) {
            dfs(1, 0, y, x);
            verify(y, x);
        }
    cout << ans;
    return 0;
}