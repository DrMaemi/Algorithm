#include <iostream>
#include <vector>
using namespace std;
struct P { int z, o; };

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        vector<P> cnt;
        if (a.front() == '0') cnt.push_back({1, 0});
        else cnt.push_back({0, 1});
        for (int i=1; i<a.size(); i++) {
            P p = cnt.back();
            if (a[i] == '0') cnt.push_back({p.z+1, p.o});
            else cnt.push_back({p.z, p.o+1});
        }
        bool fliped = 0, valid = 1;
        for (int i=a.size()-1; i>=0; i--) {
            int ai = a[i]-'0', bi = b[i]-'0';
            if (fliped) ai ^= 1;
            if (ai != bi) {
                if (cnt[i].z != cnt[i].o) { valid = 0; break; }
                fliped ^= 1;
            }
        }
        if (valid) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}