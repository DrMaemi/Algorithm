#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N;
V<V<int>> adj, tr;
V<bool> visited;
V<V<int>> CM;

void make_tr(int u) {
    visited[u] = 1;
    for (int v: adj[u])
        if (!visited[v]) {
            tr[u].push_back(v);
            make_tr(v);
        }
}

int EA(int u, bool ea) {
    int& val = CM[u][ea];
    if (val != -1)
        return val;
    if (ea) {
        val = 1;
        for (int v: tr[u])
            val += min(EA(v, 0), EA(v, 1));
    }
    else {
        val = 0;
        for (int v: tr[u])
            val += EA(v, 1);
    }
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    adj.resize(N+1);
    tr.resize(N+1);
    visited.resize(N+1);
    for (int i=1; i<N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    make_tr(1);
    CM.resize(N+1, V<int>(2, -1));
    int r = min(EA(1, 0), EA(1, 1));
    cout << r;
    return 0;
}