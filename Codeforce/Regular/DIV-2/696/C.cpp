#include <iostream>
#include <vector>
using namespace std;
#define V vector

int n;

void dfs(int sum, V<int> A, V<V<int>> D) {
    if (A.empty()) {
        cout << "YES\n";
        for (V<int> v: D) for (int x: v) cout << x << " ";
        cout << "\n";
    }
    else {
        
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        
    }
    return 0;
}