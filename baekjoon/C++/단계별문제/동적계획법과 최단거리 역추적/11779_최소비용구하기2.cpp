#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
#define V vector
struct E { int v, w; };
struct cmp {
    bool operator()(E& a, E& b) {
        return a.w > b.w;
    }
};

int n, m;
V<V<E>> adj;
V<int> dist, P;

void dijkstra(int& s) {
    priority_queue<E, V<E>, cmp> pq;
    pq.push({s, 0});
    dist[s] = 0;
    while (!pq.empty()) {
        E nx = pq.top(); pq.pop();
        for (E dt: adj[nx.v]) {
            int upt = dist[nx.v]+dt.w;
            if (upt < dist[dt.v]) {
                dist[dt.v] = upt;
                P[dt.v] = nx.v;
                pq.push({dt.v, upt});
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    adj.resize(n+1);
    dist.resize(n+1, INT_MAX);
    P.resize(n+1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int s, e;
    cin >> s >> e;
    dijkstra(s);
    cout << dist[e] << "\n";
    stack<int> path;
    for (int p=e; p!=s; p=P[p])
        path.push(p);
    cout << path.size()+1 << "\n" << s << " ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    return 0;
}