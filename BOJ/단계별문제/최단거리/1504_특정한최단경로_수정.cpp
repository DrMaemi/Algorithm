#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX
struct P { int v, c; };
struct compare {
    bool operator()(P _1, P _2) {
        return _1.c > _2.c;
    }
};

int N, E, d[3][801], via[4];
vector<vector<P>> adj;
priority_queue<P, vector<P>, compare> pq;

void dijkstra(int idx) {
    while (!pq.empty()) {
        P nx = pq.top(); pq.pop();
        for (P dt: adj[nx.v]) {
            int upt = d[idx][nx.v]+dt.c;
            if (upt < d[idx][dt.v]) {
                d[idx][dt.v] = upt;
                pq.push({dt.v, upt});
            }
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> E;
    adj.resize(N+1);
    int u, v, c;
    while (E--) {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    cin >> via[1] >> via[2]; via[0] = 1; via[3] = N;
    for (int i=0; i<3; i++) {
        fill(d[i]+1, d[i]+N+1, INF);
        pq.push({via[i], 0}); d[i][via[i]] = 0;
        dijkstra(i);
    }
    int r = INF;
    if (d[0][via[1]] != INF && d[1][via[2]] != INF && d[2][N] != INF)
        r = min(r, d[0][via[1]]+d[1][via[2]]+d[2][N]);
    if (d[0][via[2]] != INF && d[2][via[1]] != INF && d[1][N] != INF)
        r = min(r, d[0][via[2]]+d[2][via[1]]+d[1][N]);
    if (r == INF) cout << -1;
    else cout << r;
    return 0;
}