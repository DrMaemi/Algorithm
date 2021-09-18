#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i=0; i<N; i++) cin >> A[i];
        if (A[0] == A[1] && A[1] != A[2]) cout << 3 << "\n";
        else if (A[0] == A[2] && A[0] != A[1]) cout << 2 << "\n";
        else if (A[1] == A[2] && A[0] != A[1]) cout << 1 << "\n";
        else {
            int p = A[0];
            for (int i=3; i<N; i++)
                if (p != A[i]) { cout << i+1 << "\n"; break; }
        }
    }
    return 0;
}