#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V vector

int N;
V<int> W;
V<V<bool>> visited;

void dfs(int i, int t) {
    if (i == N) return;
    for (int k=-1; k<2; k++) {
        int w = abs(t+k*W[i]);
        if (!visited[i][w]) {
            visited[i][w] = 1;
            dfs(i+1, w);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    W.resize(N);
    int ws = 0;
    for (int i=0; i<N; i++) {
        cin >> W[i];
        ws += W[i];
    }
    visited.resize(N, V<bool>(ws+1));
    dfs(0, 0);
    queue<int> q;
    int M; cin >> M;
    while (M--) {
        int n; cin >> n;
        q.push(n);
    }
    while (!q.empty()) {
        int nx = q.front(); q.pop();
        if (nx > ws || !visited[N-1][nx])
            cout << "N ";
        else
            cout << "Y ";
    }
    return 0;
}