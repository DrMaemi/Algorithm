#include <iostream>
#include <vector>
using namespace std;
#define V vector
typedef long long ll;

int main() {
    int N; cin >> N;
    V<V<ll>> MZ(N, V<ll>(2));
    MZ[0][0] = 0; MZ[0][1] = 1;
    for (int i=1; i<N; i++) {
        MZ[i][0] = MZ[i-1][0]+MZ[i-1][1];
        MZ[i][1] = MZ[i-1][0];
    }
    cout << MZ[N-1][0]+MZ[N-1][1];
    return 0;
}