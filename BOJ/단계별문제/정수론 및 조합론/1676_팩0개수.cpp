#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N; cin >> N;
    int t = 0, f = 0;
    for (int i=1; i<=N; i++) {
        int n = i;
        while (!(n%2)) { t++; n /= 2; }
        n = i;
        while (!(n%5)) { f++; n /= 5; }
    }
    if (!t || !f) cout << 0;
    else cout << min(t, f);
    return 0;
}