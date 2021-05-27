#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector
struct D { int i, c, s; };
struct C { int ms, upt, pre; };

bool cmps(D& _1, D& _2) {
    return _1.s < _2.s;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    V<D> VD(N); V<C> VC(N+1, {0, 0, 0});
    for (int i=0; i<N; i++) {
        VD[i].i = i;
        cin >> VD[i].c >> VD[i].s;
    }
    sort(VD.begin(), VD.end(), cmps);
    V<int> A(N);
    int sum = 0, pre_sum = 0, pre = 0;
    for (int i=0; i<N; i++) {
        C& c = VC[VD[i].c];
        if (c.ms < VD[i].s)
            c.pre = c.upt;
        c.ms = VD[i].s;
        c.upt += c.ms;
        if (pre < c.ms) {
            A[VD[i].i] = sum-c.pre;
            pre_sum = sum;
        }
        else
            A[VD[i].i] = pre_sum-c.pre;
        pre = c.ms;
        sum += pre;
    }
    for (int r: A)
        cout << r << "\n";
    return 0;
}