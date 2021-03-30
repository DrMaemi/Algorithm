#include <iostream>
#include <vector>
using namespace std;
#define V vector
#define div 1000000007

int main() {
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        V<V<int>> CM(K+1, V<int>(N+1));
        /* CM[k][n]: 입자 레벨 k가 n개의 plane을 앞두고 있을 때
        발생하는 모든 입자 갯수 */
        fill(&CM[1][0], &CM[1][N+1], 1);
        for (int k=2; k<=K; k++) {
            CM[k][0] = 1;
            for (int n=1; n<=N; n++)
                CM[k][n] = (CM[k-1][N-n]+CM[k][n-1])%div;
        }
        cout << CM[K][N] << "\n";
    }
    return 0;
}