#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        vector<int> A(N);
        for (int i=0; i<N; i++) cin >> A[i];
        int k = 0, ans;
        while (k < K) {
            bool f = 0;
            for (int i=0; i<N-1; i++) {
                if (A[i] < A[i+1]) {
                    A[i]++; f = 1;
                    if (k == K-1) ans = i+1;
                    break;
                }
            }
            if (!f) {
                ans = -1; break;
            }
            k++;
        }
        cout << ans << "\n";
    }
    return 0;
}