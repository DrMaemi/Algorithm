#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i=0; i<N; i++) cin >> A[i];
        bool f = 1;
        for (int i=0; i<32; i++) {
            int cnt = 0;
            for (int x: A) if (x & (1 << i)) cnt++;
            if (cnt & 1) { f = 0; break; }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}