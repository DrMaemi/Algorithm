#include <iostream>
#include <vector>
using namespace std;
#define V vector

V<V<int>> pc, m;

int main() {
    int p, n, h;
    cin >> p >> n >> h;
    V<V<int>> pc(p+1), m(p+1);
    for (int i=1; i<=p; i++)
        m[i].resize(h+1, 0);
    while (n--) {
        int u, v;
        cin >> u >> v;
        pc[u].push_back(v);
    }
    for (int i=1; i<=p; i++)
        for (int _h=1; _h<=h; _h++)
            for (int rsv: pc[i])
                if (rsv <= _h)
                    m[i][_h] = max(m[i][_h], m[i][_h-rsv]+rsv);
    for (int i=1; i<=p; i++)
        cout << i << " " << m[i][h] << "\n";
    return 0;
}