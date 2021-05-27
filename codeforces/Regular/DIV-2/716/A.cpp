#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, a[100]; cin >> N;
        for (int i=0; i<N; i++) cin >> a[i];
        bool f = 1;
        for (int i=0; i<N; i++) {
            double sq = sqrt(a[i]);
            if (sq-(int)sq != 0) { f = 0; break; }
        }
        if (f) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}