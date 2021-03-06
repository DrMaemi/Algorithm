#include <iostream>
#include <vector>
using namespace std;
#define V vector

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    V<int> coins(n);
    for (int i=0; i<n; i++)
        cin >> coins[i];
    V<int> m(k+1);
    m[0] = 1;
    for (int coin: coins)
        for (int i=coin; i<=k; i++)
            m[i] += m[i-coin];
    cout << m[k];
    return 0;
}