#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, ans = 0; cin >> N;
        while (N--) { int r; cin >> r; if (r != 2) ans++; }
        cout << ans << "\n";
    }
    return 0;
}