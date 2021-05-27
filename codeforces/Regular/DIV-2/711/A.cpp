#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b) {
    if (!b) return a;
    return GCD(b, a%b);
}

ll SumOfDigits(ll n) {
    ll r = 0;
    string s = to_string(n);
    for (char _n: s) r += _n-'0';
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        ll N; cin >> N;
        for (ll i=N; i<LONG_LONG_MAX; i++)
            if (GCD(i, SumOfDigits(i)) > 1) {
                cout << i << "\n";
                break;
            }
    }
    return 0;
}