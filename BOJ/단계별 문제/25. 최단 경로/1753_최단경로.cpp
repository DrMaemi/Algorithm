#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define V vector
struct Edge { int v, w; };
struct cmp {
    bool operator()(Edge& _1, Edge& _2) {
        return _1.w > _2.w;
    }
};

int N, E;
V<V<Edge>> adj;
V<int> dist;
priority_queue<Edge, V<Edge>, cmp> pq;

void dijkstra(int start) {
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        Edge nx = pq.top(); pq.pop();
        for (Edge dt: adj[nx.v]) {
            int upt = dist[nx.v]+dt.w;
            if (upt < dist[dt.v]) {
                dist[dt.v] = upt;
                pq.push({dt.v, upt});
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> E;
    adj.resize(N+1);
    dist.resize(N+1, INT_MAX);
    int start; cin >> start;
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(start);
    for (auto it=dist.begin()+1; it!=dist.end(); it++) {
        if (*it == INT_MAX)
            cout << "INF" << "\n";
        else
            cout << *it << "\n";
    }
    return 0;
}