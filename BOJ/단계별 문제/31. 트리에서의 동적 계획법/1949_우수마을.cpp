#include <iostream>
#include <vector>
using namespace std;
#define V vector

V<int> A;
V<V<int>> adj, tr, CM;

void make_tr(int u, int v) {
    tr[u].push_back(v);
    for (int nx: adj[v])
        if (u != nx) make_tr(v, nx);
}

int dp(int u, bool f) {
    if (CM[u][f] == -1) {
        CM[u][f] = f? A[u]: 0;
        for (int v: tr[u]) {
            int t1 = dp(v, 0), t2 = 0;
            if (!f) t2 = dp(v, 1);
            CM[u][f] += max(t1, t2);
        }
    }
    return CM[u][f];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    A.resize(N+1);
    for (int i=1; i<=N; i++) cin >> A[i];
    adj.resize(N+1); tr.resize(N+1);
    for (int i=1; i<N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    make_tr(0, 1);
    CM.resize(N+1, V<int>(2, -1));
    cout << max(dp(1, 0), dp(1, 1));
    return 0;
}