#include <iostream>
using namespace std;

int main() {
    int N, K, ans = 0;
    int A[11];

    cin >> N >> K;
    for (int i=1; i<=N; i++)
        cin >> A[i];

    for (int i=N; i; i--) {
        int q = K/A[i];

        if (q) {
            ans += q;

            K = K%A[i];
        }
    }

    cout << ans;
    return 0;
}