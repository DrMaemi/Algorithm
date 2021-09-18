#include <iostream>
using namespace std;

int N, K;
int A[200], CM[200][200];

int dp(int l, int r) {
    if (CM[l][r] == 201) {
        for (int i=0; l+i<r; i++)
            CM[l][r] = min(
                CM[l][r],
                dp(l, l+i)+dp(l+i+1, r)+(A[l]!=A[l+i+1])
                );
    }
    return CM[l][r];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    fill(&CM[0][0], &CM[N-1][N], 201);
    for (int i=0; i<N; i++) {
        cin >> A[i];
        CM[i][i] = 0;
    }
    cout << dp(0, N-1);
    return 0;
}