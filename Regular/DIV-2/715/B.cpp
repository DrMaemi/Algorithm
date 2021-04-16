#include <iostream>
#include <vector>
using namespace std;
struct P { int l, r; };

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N, cnt = 0, sum = 0; cin >> N;
        string s; cin >> s;
        if (s[0] == 'M' || s[s.size()-1] == 'M') { cout << "NO\n"; continue; }
        vector<P> V(1, {0, 0});
        for (char c: s)
            if (c == 'T') { cnt++; sum++; }
            else { V.push_back({V.back().l+cnt, 0}); cnt = 0; }
        if (2*(V.size()-1) != sum) { cout << "NO\n"; continue; }

        V[V.size()-1].r = cnt;
        for (int i=V.size()-2; i>0; i--)
            V[i].r = V[i+1].r+V[i+1].l-V[i].l;
        bool f = 1;
        for (int i=1; i<V.size(); i++)
            if (i > V[i].l || V.size()-i > V[i].r) { f = 0; break; }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}