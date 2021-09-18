#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N;
V<V<int>> map;
int ans[3];

void dq(int r, int c, int l) {
    int pre = map[r][c];
    for (int i=r; i<r+l; i++)
        for (int j=c; j<c+l; j++)
            if (map[i][j] != pre) {
                l /= 3;
                for (int _i=0; _i<3; _i++)
                    for (int _j=0; _j<3; _j++)
                        dq(r+_i*l, c+_j*l, l);
                return;
            }
    ans[++pre]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    map.resize(N);
    for (int i=0; i<N; i++) {
        map[i].resize(N);
        for (int j=0; j<N; j++)
            cin >> map[i][j];
    }
    dq(0, 0, N);
    for (int i=0; i<3; i++)
        cout << ans[i] << "\n";
    return 0;
}