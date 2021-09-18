#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<string> S(N);
        for (int i=0; i<N; i++)
            cin >> S[i];
        sort(S.begin(), S.end());
        bool valid = 1;
        for (int i=0; i<N-1; i++) {
            int l = S[i].length();
            if (l <= S[i+1].length()) {
                bool f = 1;
                for (int j=0; j<l; j++)
                    if (S[i][j] != S[i+1][j]) {
                        f = 0; break;
                    }
                if (f) {
                    valid = 0; break;
                }
            }
        }
        if (valid) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}