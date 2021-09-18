#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll GCD(int a, int b) { if (!b) return a; return GCD(b, a % b); }

ll pow(int n, int p) { int r = 1; while (p--) r *= n; return r; }

int main() {
    int T; cin >> T;
    while (T--) {
        int a, b, c; cin >> a >> b >> c;
        int x, y, _x, _y, xs, xe, ys, ye;
        xs = pow(10, a); xe = pow(10, a+1);
        ys = pow(10, b); ye = pow(10, b+1);
        if (c == 1)

        for (int i=xs; i<xe; i++)
    }
    return 0;
}