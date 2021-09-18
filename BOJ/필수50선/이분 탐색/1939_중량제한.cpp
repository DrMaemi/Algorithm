#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V vector
struct E { int v, w; };

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, M, s, e;
    cin >> N >> M;
    V<V<E>> adj(N+1);
    int l = 0, h = 0;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        h = max(h, w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> s >> e;
    while (l <= h) {
        int m = (l+h)/2;
        queue<int> q;
        V<bool> visited(N+1);
        q.push(s); visited[s] = 1;
        bool f = 0;
        while (!q.empty()) {
            int nx = q.front(); q.pop();
            if (nx == e) {
                f = 1;
                break;
            }
            for (E dt: adj[nx])
                if (!visited[dt.v] && m <= dt.w) {
                    q.push(dt.v);
                    visited[dt.v] = 1;
                }
        }
        if (f) l = m+1;
        else h = m-1;
    }
    cout << h;
    return 0;
}