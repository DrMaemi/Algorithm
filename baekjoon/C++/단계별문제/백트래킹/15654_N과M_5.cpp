#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector

int N, M;

void dfs(V<int>& A, V<bool>& visited, V<int>& out) {
    if (out.size() == M) {
        for (int o: out)
            cout << o << " ";
        cout << "\n";
        return;
    }
    for (int i=0; i<N; i++) {
        if (visited[i]) continue;
        out.push_back(A[i]);
        visited[i] = 1;
        dfs(A, visited, out);
        out.pop_back();
        visited[i] = 0;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    V<int> A(N); V<bool> visited(N, 0);
    for (int i=0; i<N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    V<int> out;
    dfs(A, visited, out);
    return 0;
}