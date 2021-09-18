#include <iostream>
#include <climits>
using namespace std;
#define INF INT_MAX/2

int m[5001];

int dp(int n) {
    if (n == 3 || n == 5) return 1;
    if (n < 5) return INF;
    if (!m[n])
        m[n] = min(dp(n-5)+1, dp(n-3)+1);
    return m[n];
}

int main(void) {
    int N; cin >> N;
    int r = dp(N);
    if (r >= INF) cout << -1;
    else cout << r;
    return 0;
}