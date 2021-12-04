#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N, M;
V<V<int>> adj;
V<int> p;

int P(int i) {
    if (p[i] == i) return i;
    return p[i] = P(p[i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    adj.resize(N+1); p.resize(N+1);
    for (int i=1; i<=N; i++) {
        adj[i].resize(N+1);
        p[i] = i;
    }
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++) {
            cin >> adj[i][j];
            if (adj[i][j])
                p[P(i)] = p[P(j)];
        }
    V<int> path(M);
    for (int i=0; i<M; i++)
        cin >> path[i];
    for (int i=1; i<path.size(); i++)
        if (P(path[0]) != P(path[i])) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}