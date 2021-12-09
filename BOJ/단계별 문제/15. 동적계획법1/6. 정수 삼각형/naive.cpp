#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    int DP[501][501];
    
    cin >> N;
    cin >> DP[1][0];

    for (int i=2; i<=N; i++) {
        int n;

        cin >> n;
        DP[i][0] = DP[i-1][0]+n;
        
        for (int j=1; j<i-1; j++) {
            cin >> n;
            DP[i][j] = max(DP[i-1][j-1], DP[i-1][j])+n;
        }

        cin >> n;
        DP[i][i-1] = DP[i-1][i-2]+n;
    }

    cout << *max_element(DP[N], DP[N]+N);
    return 0;
}