#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n), MZ(k+1, -1);
    for (int i=0; i<n; i++)
        cin >> coins[i];
    MZ[0] = 0;
    for (int coin: coins)
        for (int i=coin; i<=k; i++)
            if (MZ[i-coin] != -1)
                if (MZ[i] == -1)
                    MZ[i] = MZ[i-coin]+1;
                else
                    MZ[i] = min(MZ[i], MZ[i-coin]+1);
    cout << MZ[k];
    return 0;
}