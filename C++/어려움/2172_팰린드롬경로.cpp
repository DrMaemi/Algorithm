#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

int N, L;
int m[20][20];
int CM[20][20][20][20][20];
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> L;
    for (int y=0; y<N; y++) for (int x=0; x<N; x++) {
        cin >> m[y][x];
        CM[0][y][x][y][x]++;
    }
    for (int y=0; y<N; y++) for (int x=0; x<N; x++)
        for (int i=0; i<8; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if (ny < 0 || N <= ny || nx < 0 || N <= nx)
                continue;
            if (m[y][x] == m[ny][nx])
                CM[1][y][x][ny][nx]++;
        }
    for (int l=2; l<L; l++)
        for (int y=0; y<N; y++) for (int x=0; x<N; x++)
            for (int yy=0; yy<N; yy++) for (int xx=0; xx<N; xx++)
                if (m[y][x] == m[yy][xx]) {
                    for (int i=0; i<8; i++) {
                        int ny = y+dy[i], nx = x+dx[i];
                        if (ny < 0 || N <= ny || nx < 0 || N <= nx)
                            continue;
                        for (int j=0; j<8; j++) {
                            int nyy = yy+dy[j], nxx = xx+dx[j];
                            if (nyy < 0 || N <= nyy || nxx < 0 || N <= nxx)
                                continue;
                            if (m[ny][nx] == m[nyy][nxx])
                                CM[l][y][x][yy][xx] += CM[l-2][ny][nx][nyy][nxx];
                        }
                    }
                }
    cout << accumulate(&CM[L-1][0][0][0][0], &CM[L-1][N-1][N-1][N-1][N], 0);
    return 0;
}