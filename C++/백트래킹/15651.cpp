#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> result;

void dfs(int depth);

int main(void) {
    cin >> n >> m;
    dfs(0);
    return 0;
}

void dfs(int depth) {
    if (depth == m) {
        for (int i=0; i<m; i++) {
            cout << result[i] << " ";
        } cout << "\n";
        return;
    }
    for (int i=0; i<n; i++) {
        result.push_back(i+1);
        dfs(depth+1);
        result.pop_back();
    }
}