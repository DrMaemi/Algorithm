#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int P(int i) {
    if (p[i] == -1)
        return i;
    return p[i] = P(p[i]);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    p.resize(n, -1);
    int ans = 0;
    for (int t=1; t<=m; t++) {
        int u, v;
        cin >> u >> v;
        if (P(u) == P(v)) {
            ans = t;
            break;
        }
        p[P(u)] = P(v);
    }
    cout << ans;
    return 0;
}