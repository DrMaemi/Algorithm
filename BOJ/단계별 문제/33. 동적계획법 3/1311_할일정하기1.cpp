#include <iostream>
#include <vector>
using namespace std;
#define V vector
#define MAX 200000

int N;
V<V<int>> cost;
V<int> CM;

int dp(int bit, int i) {
    if (i == N) return 0;
    if (CM[bit] == MAX)
        for (int j=0; j<N; j++)
            if (!(bit & (1 << j)))
                CM[bit] = min(CM[bit], cost[i][j]+dp(bit | (1 << j), i+1));
    return CM[bit];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    cost.resize(N, V<int>(N));
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) cin >> cost[i][j];
    CM.resize(1 << N, MAX);
    int ans = MAX;
    for (int j=0; j<N; j++)
        ans = min(ans, cost[0][j]+dp(1 << j, 1));
    cout << ans;
    return 0;
}