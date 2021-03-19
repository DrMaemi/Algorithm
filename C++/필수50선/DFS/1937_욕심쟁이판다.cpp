#include <iostream>
using namespace std;


int N, m[500][500], CM[500][500];
bool visited[500][500];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
int ans = 0;

int dp(int y, int x) {
    if (!visited[y][x]) {
        for (int i=0; i<4; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < N && m[y][x] < m[ny][nx])
                CM[y][x] = max(CM[y][x], dp(ny, nx)+1);
        }
        visited[y][x] = 1;
    }
    return CM[y][x];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int y=0; y<N; y++)
        for (int x=0; x<N; x++)
            cin >> m[y][x];
    for (int y=0; y<N; y++)
        for (int x=0; x<N; x++)
            if (!visited[y][x])
                ans = max(ans, dp(y, x));
    cout << ans+1;
    return 0;
}