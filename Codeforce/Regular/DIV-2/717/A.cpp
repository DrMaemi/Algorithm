#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, K, A[100], l = 0; cin >> N >> K;
        for (int i=0; i<N; i++) cin >> A[i];
        while (K) {
            if (l == N-1) break;
            if (A[l]) { A[l]--; A[N-1]++; K--; }
            else l++;
        }
        for (int i=0; i<N; i++) cout << A[i] << " ";
        cout << "\n";
    }
    return 0;
}