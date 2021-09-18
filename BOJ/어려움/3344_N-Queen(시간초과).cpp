#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N;
V<int> R;
V<bool> C, D, AD;

void dfs(int r) {
    if (r == N) {
        for (int c: R)
            cout << c+1 << "\n";
        exit(0);
    }
    for (int c=0; c<N; c++) {
        if (!C[c] && !D[r-c+N-1] && !AD[r+c]) {
            R[r] = c;
            C[c] = D[r-c+N-1] = AD[r+c] = 1;
            dfs(r+1);
            C[c] = D[r-c+N-1] = AD[r+c] = 0;
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    R.resize(N); C.resize(N);
    D.resize(2*N-1); AD.resize(2*N-1);
    dfs(0);
    return 0;
}