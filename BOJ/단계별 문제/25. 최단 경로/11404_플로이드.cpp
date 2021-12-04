#include <iostream>
#include <climits>
using namespace std;
#define MAX INT_MAX/2

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m, d[101][101];
    cin >> n >> m;
    fill(&d[0][0], &d[n][n+1], MAX);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
    }
    for (int u=1; u<=n; u++)
        d[u][u] = 0;
    for (int nx=1; nx<=n; nx++)
        for (int u=1; u<=n; u++) {
            d[u][u] = 0;
            for (int dt=1; dt<=n; dt++)
                d[u][dt] = min(d[u][dt], d[u][nx]+d[nx][dt]);
        }
    for (int u=1; u<=n; u++) {
        for (int v=1; v<=n; v++)
            cout << (d[u][v]!=MAX? d[u][v]: 0) << " ";
        cout << "\n";
    }
    return 0;
}