#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define V vector
typedef long long ll;
struct J { int m, v;};

bool compare_m(J _1, J _2) {
    return _1.m < _2.m;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, K; cin >> N >> K;
    V<J> jj(N);
    for (int i=0; i<N; i++) 
        cin >> jj[i].m >> jj[i].v;
    V<int> C(K);
    for (int i=0; i<K; i++)
        cin >> C[i];
    priority_queue<int> pq;
    sort(jj.begin(), jj.end(), compare_m);
    sort(C.begin(), C.end());
    int p = 0; ll r = 0;
    for (int i=0; i<K; i++) {
        for (int j=p; j<N; j++, p++) {
            if (C[i] < jj[j].m) break;
            pq.push(jj[j].v);
        }
        if (!pq.empty()) {
            r += pq.top(); pq.pop();
        }
    }
    cout << r;
    return 0;
}