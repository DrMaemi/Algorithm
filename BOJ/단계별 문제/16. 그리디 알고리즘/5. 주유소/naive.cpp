#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;
    vector<ll> dists(N-1), costs(N);

    for (int i=0; i<N-1; i++)
        cin >> dists[i];

    for (int i=0; i<N; i++)
        cin >> costs[i];

    ll cost = costs[0];
    ll ans = cost*dists[0];

    for (int i=1; i<N-1; i++) {
        cost = min(cost, costs[i]);
        ans += cost*dists[i];
    }
    
    cout << ans;
    return 0;
}