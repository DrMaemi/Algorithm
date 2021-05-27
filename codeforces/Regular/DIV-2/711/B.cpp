#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, W;
        cin >> n >> W;
        map<int, int, greater<int>> m;
        int in;
        while (n--) {
            cin >> in;
            if (m.find(in) == m.end()) m[in] = 1;
            else m[in]++;
        }
        int ans = 0;
        while (!m.empty()) {
            int _W = W;
            for (auto it=m.begin(); it!=m.end(); ) {
                if (it->first <= _W) {
                    _W -= it->first;
                    it->second--;
                    if (!it->second) m.erase(it++);
                }
                else ++it;
            }
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}