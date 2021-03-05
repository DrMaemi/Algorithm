#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V vector
struct E { int v, w; };

V<V<E>> adj;
V<bool> visited;
int _max = 0, farthest;

void dfs(int i, int sum) {
    if (visited[i]) return;
    visited[i] = 1;
    if (_max < sum) {
        _max = sum;
        farthest = i;
    }
    for (E nx: adj[i])
        dfs(nx.v, sum+nx.w);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    adj.resize(N+1); visited.resize(N+1, 0);
    for (int i=0; i<N; i++) {
        int u, v, w;
        cin >> u >> v;
        while (v != -1) {
            cin >> w;
            adj[u].push_back({v, w});
            cin >> v;
        }
    }
    dfs(1, 0);
    fill(visited.begin(), visited.end(), 0);
    _max = 0;
    dfs(farthest, 0);
    cout << _max;
    return 0;
}