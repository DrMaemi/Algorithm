#include <iostream>
using namespace std;

int M, N, A[500][500];
int m[500][500];
bool v[500][500];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

bool valid(int y, int x) {
    if (y < 0 || M <= y || x < 0 || N <= x)
        return 0;
    return 1;
}

int dp(int y, int x) {
    if (!valid(y, x))
        return 0;
    if (!v[y][x]) {
        for (int i=0; i<4; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if (A[y][x] < A[ny][nx])
                m[y][x] += dp(ny, nx);
        }
        v[y][x] = 1;
    }
    return m[y][x];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> M >> N;
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            cin >> A[i][j];
    m[0][0] = v[0][0] = 1;
    cout << dp(M-1, N-1);
    return 0;
}