#include <iostream>
#include <vector>
using namespace std;
#define V vector

bool cycle(V<V<int>>& adj, V<bool>& visited, int u, int v) {
    if (visited[v]) return 1;
    visited[v] = 1;
    bool r = 0;
    for (int nx: adj[v])
        if (nx != u)
            r |= cycle(adj, visited, v, nx);
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, T = 0;
    cin >> N >> M;
    while (N) {
        V<V<int>> adj(N+1);
        V<int> belongs(N+1);
        V<bool> visited(N+1);
        while (M--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for (int i=1; i<=N; i++)
            if (!visited[i])
                ans += cycle(adj, visited, 0, i)? 0: 1;
        cout << "Case " << ++T << ": ";
        if (!ans) cout << "No trees.\n";
        else if (ans == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
        cin >> N >> M;
    }
    return 0;
}