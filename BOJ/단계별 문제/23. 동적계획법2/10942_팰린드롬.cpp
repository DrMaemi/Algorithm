#include <iostream>
#include <vector>
using namespace std;
#define V vector

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    V<int> A(N+1);
    V<V<bool>> m(N+1, V<bool>(N+1));
    for (int i=1; i<=N; i++)
        cin >> A[i];
    for (int i=1; i<N; i++) {
        m[i][i] = 1;
        if (A[i] == A[i+1])
            m[i][i+1] = 1;
    }
    m[N][N] = 1;
    for (int s=2; s<N; s++) {
        for (int l=1; l<=N-s; l++) {
            int r = l+s;
            if (A[l] == A[r] && m[l+1][r-1])
                m[l][r] = 1;
        }
    }
    int M; cin >> M;
    while (M--) {
        int l, r; cin >> l >> r;
        cout << m[l][r] << "\n";
    }
    return 0;
}