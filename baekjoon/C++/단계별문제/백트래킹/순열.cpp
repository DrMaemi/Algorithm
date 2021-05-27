#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> result;
vector<bool> visited;

void dfs(int depth);

int main(void) {
    int tmp;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        visited.push_back(false);
    }
    dfs(0);
    return 0;
}

void dfs(int depth) {
    if (depth == m) {
        for (int i=0; i<m; i++) {
            cout << result[i] << "\n";
        }
        return;
    }
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            result.push_back(i+1);
            dfs(depth+1);
            visited[i] = false;
            result.pop_back();
        }
    }
}