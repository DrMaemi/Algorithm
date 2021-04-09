#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n+1), CM(n, -1);
    for (int i=1; i<=n; i++) cin >> a[i];
    CM[1] = a[2]-2;
    for (int i=2; i<n; i++) CM[i] = CM[i-1]+a[i+1]-a[i-1]-2;
    while (q--) {
        int l, r; cin >> l >> r;
        int ans;
        if (l == r) ans = k-1;
        else ans = (a[l+1]-2)+(k-a[r-1]-1)+CM[r-1]-CM[l];
        cout << ans << "\n";
    }
    return 0;
}