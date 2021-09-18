#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2000
typedef long long ll;

ll CM[MAX][MAX], A[MAX];

ll dp(int l, int r) {
    if (l == r) return 0;
    if (CM[l][r] == -1)
        CM[l][r] = A[r]-A[l]+min(dp(l, r-1), dp(l+1, r));
    return CM[l][r];
}

int main() {
    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    sort(A, A+N);
    fill(&CM[0][0], &CM[N-1][N], -1);
    cout << dp(0, N-1);
    return 0;
}