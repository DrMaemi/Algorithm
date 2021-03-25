#include <iostream>
#include <vector>
using namespace std;
#define V vector
struct E { int v, w; };

int N, r = 0, f = 1;
V<V<E>> adj;
V<bool> v;

void dfs(int u, int s) {
    if (v[u]) return;
    v[u] = 1;
    if (r < s) {
        r = s; f = u;
    }
    for (E nx: adj[u])
        dfs(nx.v, s+nx.w);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    adj.resize(N+1); v.resize(N+1);
    for (int i=1; i<N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i=0; i<2; i++) {
        fill(v.begin(), v.end(), 0);
        dfs(f, 0);
    }
    cout << r;
    return 0;
}