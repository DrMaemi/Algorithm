#include <iostream>
#include <climits>
using namespace std;

int N, M;
int map[1001][1001];
int CM[1001][1001][3];
bool visited[1001][1001];
int dy[] = {0, 1, 0};
int dx[] = {1, 0, -1};
int _max = INT_MIN;

// d : dir
void dfs(int y, int x, int d, int& sum) {
    if (y == N && x == M) {
        _max = max(_max, sum+map[y][x]);
        return;
    }
    sum += map[y][x];
    if (!visited[y][x] && CM[y][x][d] < sum) {
        visited[y][x] = 1;
        CM[y][x][d] = sum;
        for (int i=0; i<3; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if (0 < ny && ny <= N && 0 < nx && nx <= M)
                dfs(ny, nx, i, sum);
        }
        visited[y][x] = 0;
    }
    sum -= map[y][x];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            cin >> map[i][j];
    fill(&CM[1][1][0], &CM[N][M][3], INT_MIN);
    int sum = 0;
    dfs(1, 1, 1, sum);
    cout << _max;
    return 0;
}