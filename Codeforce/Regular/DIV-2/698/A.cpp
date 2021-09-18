#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        map<int, int> m;
        for (int i=0; i<N; i++) {
            int n; cin >> n;
            if (m.find(n) == m.end()) m[n] = 1;
            else m[n]++;
        }
        int ans = 0;
        while (!m.empty()) {
            for (auto it=m.begin(); it!=m.end(); ) {
                if (!--it->second) m.erase(it++);
                else it++;
            }
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}