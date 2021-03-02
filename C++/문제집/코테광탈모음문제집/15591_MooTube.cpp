#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define V vector
struct E { int v, c; };
struct cmp {
    bool operator()(E& _1, E& _2) {
        return _1.c > _2.c;
    }
};

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    V<V<E>> adj(N+1);
    for (int i=0; i<N-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    priority_queue<E, V<E>, cmp> pq;
    V<V<int>> d(N+1); V<bool> filled(N+1, 0);

    for (int i=1; i<=N; i++)
        d[i].resize(N+1, INT_MAX);

    while (Q--) {
        int k, u; cin >> k >> u;
        if (!filled[u]) {
            pq.push({u, 0});
            V<bool> visited(N+1, 0);
            while (!pq.empty()) {
                E nx = pq.top(); pq.pop();
                for (E dt: adj[nx.v]) {
                    int _min = dt.c < d[u][nx.v]? dt.c:d[u][nx.v];
                    if (_min < d[u][dt.v] && !visited[dt.v]) {
                        d[u][dt.v] = _min;
                        pq.push({dt.v, _min});
                        visited[dt.v] = 1;
                    }
                }
            }
            filled[u] = 1;
        }
        d[u][u] = -1;
        int r = 0;
        for (int i=1; i<=N; i++)
            if (k <= d[u][i]) r++;
        
        cout << r << "\n";
    }
    return 0;
}