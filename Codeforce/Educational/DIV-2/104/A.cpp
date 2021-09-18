#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int _min = a[0], ans = 0;
        for (int i=1; i<n; i++)
            if (_min < a[i]) { ans = n-i; break; }
        cout << ans << "\n";
    }
    return 0;
}