#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N, M;
V<int> A;
V<V<bool>> visited;

void dfs(int i, int w) {
    if (i != N+1 && !visited[i][w]) {
        visited[i][w] = 1;
        dfs(i+1, w+A[i]);
        dfs(i+1, w);
        dfs(i+1, abs(w-A[i]));
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    A.resize(N);
    int ws = 0;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        ws += A[i];
    }
    visited.resize(N+1, V<bool>(ws+1));
    dfs(0, 0);
    cin >> M;
    while (M--) {
        int n; cin >> n;
        if (ws < n || !visited[N][n])
            cout << "N" << " ";
        else
            cout << "Y" << " ";
    }
    return 0;
}