#include <iostream>
#include <vector>
using namespace std;
#define V vector

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    V<V<int>> map(N+1, V<int>(N+1));
    V<V<int>> MZ(N+1, V<int>(N+1));
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++) {
            cin >> map[i][j];
            MZ[i][j] = MZ[i-1][j]+MZ[i][j-1]-MZ[i-1][j-1]+map[i][j];
        }
    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cout << MZ[x2][y2]-MZ[x2][y1-1]-MZ[x1-1][y2]+MZ[x1-1][y1-1] << "\n";
    }
    return 0;
}