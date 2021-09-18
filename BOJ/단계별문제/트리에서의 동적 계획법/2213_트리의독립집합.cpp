#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector

V<int> W, ans;
V<V<int>> adj, tr, CM;
V<bool> visited;

void make_tr(int u) {
    for (int v: adj[u])
        if (!visited[v]) {
            visited[v] = 1;
            tr[u].push_back(v);
            make_tr(v);
        }
}

int dp(int u, bool inc) {
    if (!CM[u][inc])
        if (inc) {
            CM[u][inc] = W[u];
            for (int v: tr[u])
                CM[u][inc] += dp(v, 0);
        }
        else
            for (int v: tr[u])
                CM[u][inc] += max(dp(v, 0), dp(v, 1));
    return CM[u][inc];
}

void find(int u, bool inc) {
    if (inc) {
        ans.push_back(u);
        for (int v: tr[u])
            find(v, 0);
    }
    else
        for (int v: tr[u])
            CM[v][0] < CM[v][1]? find(v, 1): find(v, 0);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    W.resize(N+1); adj.resize(N+1);
    for (int i=1; i<=N; i++)
        cin >> W[i];
    for (int i=1; i<N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tr.resize(N+1); visited.resize(N+1);
    visited[1] = 1; make_tr(1);
    CM.resize(N+1, V<int>(2));
    cout << max(dp(1, 0), dp(1, 1)) << "\n";
    CM[1][0] < CM[1][1]? find(1, 1): find(1, 0);
    sort(ans.begin(), ans.end());
    for (int x: ans) cout << x << " ";
    return 0;
}