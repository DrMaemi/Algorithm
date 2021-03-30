#include <iostream>
#include <climits>
using namespace std;

int n, p[100001];

int quary(int x) {
    if (p[x]) return p[x];
    if (x > n) return INT_MAX;
    cout << "? " << x << "\n";
    cout.flush();
    cin >> p[x]; return p[x];
}

int main() {
    cin >> n;
    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int m = (l+r)/2;
        if (quary(m) < quary(m+1)) r = m-1, ans = m;
        else l = m+1;
    }
    cout << "! " << ans << "\n";
    cout.flush();
    return 0;
}