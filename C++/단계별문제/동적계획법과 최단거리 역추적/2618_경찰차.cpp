#include <iostream>
#include <vector>
using namespace std;
#define V vector
struct L { int y, x; };

int N, W;
V<L> w;
V<V<int>> m; V<int> p;

int dist(L _1, L _2) {
    return abs(_1.y-_2.y)+abs(_1.x-_2.x);
}

int dp(int L1, int L2) {
    if (L1 == W-1 || L2 == W-1)
        return 0;
    int nx = max(L1, L2)+1;
    if (m[L1][L2] == -1) 
        m[L1][L2] = min(
            dp(nx, L2)+dist(w[L1], w[nx]),
            dp(L1, nx)+dist(w[L2], w[nx])
        );
    return m[L1][L2];
}

void find(int L1, int L2) {
    if (L1 == W-1 || L2 == W-1)
        return;
    int nx = max(L1, L2)+1;
    int _1 = m[nx][L2]+dist(w[L1], w[nx]);
    int _2 = m[L1][nx]+dist(w[L2], w[nx]);
    if (_1 < _2) {
        p[nx] = 1;
        find(nx, L2);
    }
    else {
        p[nx] = 2;
        find(L1, nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> W; W += 2;
    w.resize(W); m.resize(W); p.resize(W);
    for (int i=0; i<W; i++)
        m[i].resize(W, -1);
    for (int i=2; i<W; i++)
        cin >> w[i].y >> w[i].x;
    w[0] = {1, 1}; w[1] = {N, N};
    cout << dp(0, 1) << "\n";
    find(0, 1);
    for (int i=2; i<W; i++)
        cout << p[i] << "\n";
    return 0;
}