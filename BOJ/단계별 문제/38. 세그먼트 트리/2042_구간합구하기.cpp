#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

vector<ll> A, seg_tr;

ll init(int s, int e, int i) {
    if (s == e)
        return seg_tr[i] = A[s];
    int m = (s+e)/2;
    return seg_tr[i] = init(s, m, 2*i)+init(m+1, e, 2*i+1);
}

ll sum(int s, int e, int i, int l, int r) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return seg_tr[i];
    int m = (s+e)/2;
    return sum(s, m, 2*i, l, r)+sum(m+1, e, 2*i+1, l, r);
}

// t: target idx, which would be updated.
void update(int s, int e, int i, int t, ll d) {
    if (t < s || e < t) return;
    seg_tr[i] += d;
    if (s != e) {
        int m = (s+e)/2;
        update(s, m, 2*i, t, d);
        update(m+1, e, 2*i+1, t, d);
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, M, K;
    cin >> N >> M >> K;
    A.resize(N);
    for (int i=0; i<N; i++)
        cin >> A[i];
    int h = (int)ceil(log2(N))+1;
    seg_tr.resize(1 << h);
    init(0, N-1, 1);
    K += M;
    while (K--) {
        int a, b; ll c;
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            ll d = c-A[b];
            A[b] = c;
            update(0, N-1, 1, b, d);
        }
        else
            cout << sum(0, N-1, 1, b-1, c-1) << "\n";
    }
    return 0;
}