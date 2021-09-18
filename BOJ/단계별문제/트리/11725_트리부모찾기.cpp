#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N;
V<V<int>> adj;
V<int> parent;

void find_parent(int i) {
    for (int nx: adj[i])
        if (!parent[nx]) {
            parent[nx] = i;
            find_parent(nx);
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    adj.resize(N+1); parent.resize(N+1, 0);
    for (int i=1; i<N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_parent(1);
    for (int i=2; i<=N; i++)
        cout << parent[i] << "\n";
    return 0;
}