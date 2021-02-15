#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, V, E, g[20001];
vector<vector<int>> adj;
queue<int> q;

void q_clear() {
    queue<int> emp; swap(q, emp);
}

bool is_bipartize() {
    int cur_g = 1, nxt_g = 2;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int cur = q.front(); q.pop();
            for (int nx: adj[cur]) {
                if (!g[nx]) {
                    g[nx] = nxt_g;
                    q.push(nx);
                }
                else if (g[nx] == cur_g)
                    return 0;
            }
        }
        cur_g = nxt_g;
        nxt_g = cur_g == 1 ? 2 : 1;
    }
    return 1;
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> V >> E;
        adj.clear(); adj.resize(V+1);
        int u, v;
        for (int i=0; i<E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool f = 1;
        fill(g+1, g+V+1, 0); q_clear();
        for (int i=1; i<=V; i++) {
            if (g[i]) continue;
            q.push(i); g[i] = 1;
            if (!is_bipartize()) {
                f = 0; break;
            }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}