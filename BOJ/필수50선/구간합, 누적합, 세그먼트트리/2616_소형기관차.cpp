#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N, M;
V<int> CS;
V<V<int>> CM;

int dp(int r, int k) {
    if (!k || r < M*k)
        return 0;
    if (!CM[r][k]) {
        CM[r][k] = dp(r-1, k);
        CM[r][k] = max(CM[r][k], dp(r-M, k-1)+CS[r]-CS[r-M]);
    }
    return CM[r][k];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    CS.resize(N+1);
    int sum = 0;
    for (int i=1; i<=N; i++) {
        int n; cin >> n;
        sum += n;
        CS[i] = sum;
    }
    cin >> M;
    CM.resize(N+1, V<int>(3));
    cout << dp(N, 3);
    return 0;
}