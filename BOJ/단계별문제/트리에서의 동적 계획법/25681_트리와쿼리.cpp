#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V vector

int N, R, Q;
V<V<int>> adj;
V<int> CM;
V<bool> visited;

int dfs(int u) {
    visited[u] = 1;
    for (int v: adj[u])
        if (!visited[v])
            CM[u] += dfs(v);
    return CM[u];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, R, Q;
    cin >> N >> R >> Q;
    adj.resize(N+1);
    CM.resize(N+1, 1);
    visited.resize(N+1);
    for (int i=1; i<N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(R);
    while (Q--) {
        int r; cin >> r;
        cout << CM[r] << "\n";
    }
    return 0;
}