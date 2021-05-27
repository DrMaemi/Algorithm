#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector
struct L { int r, c; };
struct C { L l; int i; };
struct P { int Ci, d; };

int N, M, ans = 250000;
V<L> VH;
V<C> VC;
V<V<P>> VPP;
V<bool> selected;

bool cmp(P& _1, P& _2) {
    return _1.d < _2.d;
}

int dist(L& _1, L& _2) {
    return abs(_1.r-_2.r)+abs(_1.c-_2.c);
}

void dfs(int d, int _i) {
    if (d == M) {
        int sum = 0;
        for (V<P> VP: VPP)
            for (P p: VP)
                if (selected[p.Ci]) {
                    sum += p.d;
                    break;
                }
        ans = min(ans, sum);
        return;
    }
    for (int i=_i; i<VC.size(); i++) {
        selected[i] = 1;
        dfs(d+1, i+1);
        selected[i] = 0;
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    int n, Cs = 0;
    for (int r=0; r<N; r++)
        for (int c=0; c<N; c++) {
            cin >> n;
            if (n == 1)
                VH.push_back({r, c});
            else if (n == 2)
                VC.push_back({{r, c}, Cs++});
        }
    VPP.resize(VH.size());
    for (int i=0; i<VH.size(); i++) {
        for (int Ci=0; Ci<VC.size(); Ci++)
            VPP[i].push_back({Ci, dist(VH[i], VC[Ci].l)});
        sort(VPP[i].begin(), VPP[i].end(), cmp);
    }
    selected.resize(Cs);
    dfs(0, 0);
    cout << ans;
    return 0;
}