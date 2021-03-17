#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define MAX INT_MAX/2
#define V vector

int n, m, d[101][101], P[101][101];
V<int> path;

void find_path(int s, int e) {
    if (!P[s][e]) {
        path.push_back(s);
        path.push_back(e);
        return;
    }
    find_path(s, P[s][e]);
    path.pop_back();
    find_path(P[s][e], e);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    fill(&d[1][1], &d[n][n+1], MAX);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
    }
    for (int nx=1; nx<=n; nx++)
        for (int u=1; u<=n; u++) {
            d[u][u] = 0;
            for (int v=1; v<=n; v++) {
                int upt = d[u][nx]+d[nx][v];
                if (upt < d[u][v]) {
                    d[u][v] = upt;
                    P[u][v] = nx;
                }
            }
        }
    for (int u=1; u<=n; u++) {
        for (int v=1; v<=n; v++)
            cout << (d[u][v] != MAX? d[u][v]: 0) << " ";
        cout << "\n";
    }
    for (int u=1; u<=n; u++)
        for (int v=1; v<=n; v++) {
            if (u == v) {
                cout << 0 << "\n";
                continue;
            }
            find_path(u, v);
            cout << path.size() << " ";
            for (int p: path) cout << p << " ";
            cout << "\n";
            V<int> emp; swap(path, emp);        
        }
    return 0;
}