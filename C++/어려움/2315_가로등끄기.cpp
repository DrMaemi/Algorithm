#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define V vector
#define MAX LONG_LONG_MAX
typedef long long ll;
struct P { int p, c; };

int N, M;
V<P> A;
V<ll> CS;
V<V<V<ll>>> CM;

ll dp(int l, int r, int f) {
    if (l == 1 && r == N)
        return 0;
    if (!CM[l][r][f]) {
        ll c = CS[N]-CS[r]+CS[l-1];
        int d = f? r: l;
        ll _min = min(
            l-1? dp(l-1, r, 0)+abs(A[d].p-A[l-1].p)*c: MAX,
            r < N? dp(l, r+1, 1)+abs(A[d].p-A[r+1].p)*c: MAX
            );
        CM[l][r][f] = _min;
    }
    return CM[l][r][f];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    A.resize(N+1); CS.resize(N+1);
    CM.resize(N+1, V<V<ll>>(N+1, V<ll>(2)));
    for (int i=1; i<=N; i++) {
        cin >> A[i].p >> A[i].c;
        CS[i] = CS[i-1]+A[i].c;
    }
    cout << dp(M, M, 0);
    return 0;
}