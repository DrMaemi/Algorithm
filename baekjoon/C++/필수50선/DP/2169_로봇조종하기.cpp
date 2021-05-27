#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define V vector
#define MIN INT_MIN/2

int N, M;
V<V<int>> map;
V<V<V<int>>> CM;
V<V<bool>> visited;
int dy[] = {0, 1, 0};
int dx[] = {1, 0, -1};

int dp(int y, int x, int d) {
    if (y == N-1 && x == M-1)
        return map[y][x];
    if (CM[y][x][d] == MIN) {
        visited[y][x] = 1;
        int _max = MIN;
        for (int i=0; i<3; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx])
                _max = max(_max, dp(ny, nx, i));
        }
        CM[y][x][d] = _max+map[y][x];
        visited[y][x] = 0;
    }
    return CM[y][x][d];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    map.resize(N, V<int>(M));
    visited.resize(N, V<bool>(M));
    CM.resize(N, V<V<int>>(M, V<int>(3, MIN)));
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> map[i][j];
    cout << dp(0, 0, 0);
    return 0;
}