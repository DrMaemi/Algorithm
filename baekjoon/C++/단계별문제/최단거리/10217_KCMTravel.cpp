#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef struct Edge {
    int v, c, d;
} E;
struct compare {
    bool operator()(E& _1, E& _2) {
        if (_1.d != _2.d) return _1.d > _2.d;
        return _1.c > _2.c;
    }
};

int delay[101][10001];

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    int N, M, K;
    while (T--) {
        cin >> N >> M >> K;
        vector<vector<E>> adj(N+1);
        for (int i=2; i<=N; i++) for (int j=0; j<=M; j++)
            delay[i][j] = INT_MAX;
        int u, v, c, d;
        while (K--) {
            cin >> u >> v >> c >> d;
            adj[u].push_back({v, c, d});
        }
        priority_queue<E, vector<E>, compare> q;
        q.push({1, 0, 0});
        while (!q.empty()) {
            E nx = q.top(); q.pop();
            for (E e: adj[nx.v]) {
                bool f = 0;
                for (int m=M; m>=e.c; m--) {
                    if (e.c <= m && delay[nx.v][m-e.c] != INT_MAX) {
                        int upt = delay[nx.v][m-e.c]+e.d;
                        if (upt < delay[e.v][m]) {
                            delay[e.v][m] = upt;
                            f = 1;
                        }
                    }
                }
                if (f) q.push(e);
            }
        }
        if (delay[N][M] == INT_MAX) cout << "Poor KCM\n";
        else cout << delay[N][M] << "\n";
    }
    return 0;
}