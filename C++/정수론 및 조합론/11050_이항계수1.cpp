#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
#define f(x) factorial(x)

ll memo[11];

ll factorial(int n) {
    if (!n || n == 1) return 1;
    if (!memo[n])
        memo[n] = n*f(n-1);
    return memo[n];
}

ll solve(int N, int K) {
    return f(N)/(f(N-K)*f(K));
}

int main(void) {
    int N, K;
    cin >> N >> K;
    cout << solve(N, K);
    return 0;
}