#include <iostream>
using namespace std;

int N, L;
int m[100][100], mm[200][100];
bool put[200][100];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> L;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            cin >> m[i][j];
            mm[i][j] = m[i][j];
        }
    for (int j=0; j<N; j++)
        for (int i=0; i<N; i++)
            mm[N+j][i] = m[i][j];
    int ans = 0;
    for (int i=0; i<2*N; i++) {
        int pre = mm[i][0];
        bool valid = 1;
        for (int j=1; j<N; j++) {
            if (abs(mm[i][j]-pre) > 1) {
                valid = 0;
                break;
            }
            if (mm[i][j] < pre) {
                int end = j+L-1;
                if (end < N) {
                    for (int p=j; p<=end; p++)
                        if (mm[i][p] != mm[i][j] || put[i][p]) {
                            valid = 0;
                            break;
                        }
                    if (valid) {
                        for (int p=j; p<=end; p++)
                            put[i][p] = 1;
                        j = end;
                    }
                    else break;
                }
                else {
                    valid = 0;
                    break;
                }
            }
            else if (mm[i][j] > pre) {
                int start = j-L;
                if (start < 0) {
                    valid = 0;
                    break;
                }
                else {
                    for (int p=start; p<j; p++)
                        if (mm[i][p] != mm[i][start] || put[i][p]) {
                            valid = 0;
                            break;
                        }
                    if (valid) {
                        for (int p=start; p<j; p++)
                            put[i][p] = 1;
                    }
                    else break;
                }
            }
            pre = mm[i][j];
        }
        if (valid) ans++;
    }
    cout << ans;
    return 0;
}