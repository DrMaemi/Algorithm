#include <iostream>
using namespace std;

int T, N;
int m[41][2], A[2];

int* dp(int n) {
    if (!m[n][0] && !m[n][1]) {
        m[n][0] = dp(n-2)[0]+dp(n-1)[0];
        m[n][1] = dp(n-2)[1]+dp(n-1)[1];
    }
    return m[n];
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    m[0][0] = 1; m[0][1] = 0;
    m[1][0] = 0; m[1][1] = 1;
    while (T--) {
        cin >> N;
        cout << dp(N)[0] << " " << dp(N)[1] << "\n";
    }
    return 0;
}