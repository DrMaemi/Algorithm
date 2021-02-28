#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector
struct P { int c, s; };

int idx(V<P>& v, int s) {
    int l = 0, r = v.size()-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (v[m].s < s) l = m+1;
        else r = m-1;
    }
    return r;
}

bool compare(P _1, P _2) {
    return _1.s < _2.s;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    V<P> v(N); V<int> r(N+1, 0);
    for (int i=0; i<N; i++)
        cin >> v[i].c >> v[i].s;
    V<P> vv = v;
    sort(vv.begin(), vv.end(), compare);
    for (int i=0; i<N; i++) {
        for (int ii=0; ii<=idx(vv, v[i].s); ii++)
            if (vv[ii].c != v[i].c)
                r[i] += vv[ii].s;
        cout << r[i] << "\n";
    }
    return 0;
}