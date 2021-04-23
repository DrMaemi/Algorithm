#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int T; cin >> T;
    while (T--) {
        ll N, div, ans = 0; cin >> N;
        div = N/2050;
        if (!div || N%2050) { cout << "-1\n"; continue; }
        string s = to_string(div);
        for (char c: s) ans += c-'0';
        cout << ans << "\n";
    }
    return 0;
}