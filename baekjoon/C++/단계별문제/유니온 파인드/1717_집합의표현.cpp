#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N, M;
V<int> p;

int P(int i) {
    if (p[i] == i) return i;
    return p[i] = P(p[i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    p.resize(N);
    for (int i=0; i<N; i++)
        p[i] = i;
    while (M--) {
        int o, u, v;
        cin >> o >> u >> v;
        if (!o)
            p[P(u)] = P(v);
        else if (P(u) == P(v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}