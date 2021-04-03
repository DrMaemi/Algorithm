#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector
#define MAX 100000

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    V<bool> check(MAX+1, 1);
    for (int i=2; i*i<=MAX; i++)
        if (check[i])
            for (int j=i*i; j<=MAX; j+=i)
                check[j] = 0;
    V<int> divs;
    for (int i=2; i<=MAX; i++)
        if (check[i]) divs.push_back(i);

    int T; cin >> T;
    while (T--) {
        int d, f = 0; cin >> d;
        for (int div: divs)
            if (d < div) {
                if (f) { cout << f*div << "\n"; break; }
                f = div;
                d += div-1;
            }
    }
    return 0;
}