#include <iostream>
#include <climits>
using namespace std;

int N, S[500][2], m[500][500];

int dp(int l, int r) {
    if (l == r) return 0;
    if (!m[l][r]) {
        int _min = INT_MAX;
        for (int i=l; i<r; i++) {
            _min = min(
                    _min,
                    dp(l, i)+dp(i+1, r)+S[l][0]*S[i][1]*S[r][1]
                    );
        }
        m[l][r] = _min;
    }
    return m[l][r];
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) 
        cin >> S[i][0] >> S[i][1];
    cout << dp(0, N-1);
    return 0;
}