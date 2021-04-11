#include <iostream>
#include <vector>
using namespace std;
#define div 1000000007
typedef long long ll;

int main() {
    int T; cin >> T;
    while (T--) {
        ll N, n, _min = div; cin >> N;
        vector<ll> A(N);
        cin >> A[0]; n = A[0];
        for (int i=1; i<N; i++) {
            cin >> A[i]; n &= A[i];
            _min = min(_min, A[i]);
        }
        if (n != _min) cout << 0 << "\n";
        else {
            ll ans = 1, cnt = 0;
            for (int i=0; i<N; i++) {
                if (A[i] == _min) cnt++;
                if (i <= N-3) ans = ((i+1)*ans) % div;
            }
            ans = ((ans*cnt % div)*(cnt-1 % div)) % div;
            cout << ans << "\n";
        }
    }
    return 0;
}