#include <iostream>
#include <vector>
using namespace std;
#define div 1000000007
#define V vector

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        V<V<int>> CM(N+2, V<int>(K+2));
        for (int i=0; i<=N+1; i++)
            CM[i][K] = 1;
        int ans = 1;
        for (int k=K-1; k>=1; k--)
            if ((K-k) & 1) {
                CM[N][k] = CM[N-1][k+1];
                for (int n=N-1; n>=1; n--)
                    CM[n][k] = (CM[n-1][k+1]+CM[n+1][k])%div;
                ans = (ans+CM[1][k])%div;
            }
            else {
                CM[1][k] = CM[2][k+1];
                for (int n=2; n<=N; n++)
                    CM[n][k] = (CM[n+1][k+1]+CM[n-1][k])%div;
                ans = (ans+CM[N][k])%div;
            }
        cout << ans << "\n";
    }
    return 0;
}