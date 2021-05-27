#include <iostream>
using namespace std;
#define div 1000000007
typedef long long ll;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        ll ans = 1;
        while (K--) ans = (ans*N)%div;
        cout << ans << "\n";
    }
    return 0;
}