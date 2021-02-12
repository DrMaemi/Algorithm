#include <iostream>
using namespace std;
#define divisor 10007

int memo[1001][1001];

int solve(int N, int K) {
    if (!K || N == K) return 1;
    if (!memo[N][K])
        memo[N][K] = (solve(N-1, K)+solve(N-1, K-1))%divisor;
    return memo[N][K];
}

int main(void) {
    int N, K;
    cin >> N >> K;
    cout << solve(N, K);
}