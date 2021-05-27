#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector
typedef long long ll;

V<ll> items;

void dfs(int l, int r, V<ll>& v, ll s) {
    if (l > r) {
        v.push_back(s);
        return;
    }
    dfs(l+1, r, v, s);
    dfs(l+1, r, v, s+items[l]);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, C;
    cin >> N >> C;
    V<ll> G1, G2;
    items.resize(N);
    for (int i=0; i<N; i++)
        cin >> items[i];
    dfs(0, N/2, G1, 0);
    dfs(N/2+1, N-1, G2, 0);
    sort(G2.begin(), G2.end());
    ll ans = 0;
    for (ll s: G1)
        ans += upper_bound(G2.begin(), G2.end(), C-s)-G2.begin();
    cout << ans;
    return 0;
}