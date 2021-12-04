#include <iostream>
using namespace std;
typedef long long ll;

int T, N, M;
ll memo[30][30];

ll cases(int M, int N) {
    if (!N || M == N) return 1;
    if (!memo[M][N])
        memo[M][N] = cases(M-1, N)+cases(M-1, N-1);
    return memo[M][N];
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N >> M;
        if (!N) cout << 0 << "\n";
        else cout << cases(M, N) << "\n";
    }
    return 0;
}