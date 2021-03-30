#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Mon { int a, b; };

bool cmp(Mon& _1, Mon& _2) {
    return _1.a < _2.a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int A, B, n;
        cin >> A >> B >> n;
        vector<Mon> Mons(n);
        for (int i=0; i<n; i++) cin >> Mons[i].a;
        for (int i=0; i<n; i++) cin >> Mons[i].b;
        sort(Mons.begin(), Mons.end(), cmp);
        bool f = 1;
        for (int i=0; i<n; i++) {
            Mon& m = Mons[i];
            int _min = min((B+m.a-1)/m.a, (m.b+A-1)/A);
            B -= _min*m.a; m.b -= _min*A;
            if (0 < m.b || (B < 0 && i < n-1)) {
                f = 0; break;
            }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}