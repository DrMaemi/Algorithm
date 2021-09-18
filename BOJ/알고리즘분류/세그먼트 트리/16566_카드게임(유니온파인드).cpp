#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector

struct UnionFind {
    V<int> parent;
    UnionFind(int n): parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int Find(int x) {
        return x == parent[x]? x: parent[x] = Find(parent[x]);
    }
    void Union(int a, int b) {
        a = Find(a), b = Find(b);
        if (a > b) swap(a, b);
        parent[a] = b;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    V<int> A(M); UnionFind UF(M+1);
    for (int i=0; i<M; i++) cin >> A[i];
    sort(A.begin(), A.end());
    while (K--) {
        int n; cin >> n;
        auto it = upper_bound(A.begin(), A.end(), n);
        int idx = UF.Find(it-A.begin());
        cout << A[idx] << "\n";
        if (idx < M-1) UF.Union(idx, idx+1);
    }
}