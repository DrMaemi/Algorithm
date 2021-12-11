#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, ans = -1000;

    cin >> N;
    
    vector<int> DP(N+1, -1000);

    for (int i=1; i<=N; i++) {
        int n;

        cin >> n;
        DP[i] = max(DP[i-1]+n, n);
        ans = max(ans, DP[i]);
    }

    cout << ans;
    return 0;
}