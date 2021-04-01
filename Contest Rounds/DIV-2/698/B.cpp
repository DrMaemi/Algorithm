#include <iostream>
using namespace std;

bool hasd(int& d, int n) {
    while (n) {
        if (n%10 == d) return 1;
        n /= 10;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int q, d; cin >> q >> d;
        while (q--) {
            int n; cin >> n;
            bool f = 0;
            if (hasd(d, n)) f = 1;
            while (!f && 0 < n) {
                n -= d;
                f = hasd(d, n)? 1: 0;
            }
            if (f) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}