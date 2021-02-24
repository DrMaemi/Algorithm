#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    int _min = INT_MAX, _max = INT_MIN;
    vector<int> T(N);
    for (int i=0; i<N; i++) {
        cin >> T[i];
        _min = min(_min, T[i]);
        _max = max(_max, T[i]);
    }
    ll l = _min, r = (ll)M*_max;
    while (l <= r) {
        ll m = (l+r)/2, n = 0;
        for (int t: T) n += m/t;
        if (M <= n) r = m-1;
        else l = m+1;
    }
    cout << l;
    return 0;
}