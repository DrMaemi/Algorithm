#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while (T--) {
        ll n, m, x;
        cin >> n >> m >> x;
        int c = (x-1)/n, r = (x-1)%n;
        cout << m*r+c+1 << "\n";
    }
    return 0;
}