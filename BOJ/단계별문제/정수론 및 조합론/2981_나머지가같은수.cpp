#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct Pair {
    int i, j;
} P;

int gcd(int _1, int _2) {
    return _1 % _2 ? gcd(_2, _1 % _2) : _2;
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, A[101];cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    sort(A, A+N); vector<P> m;
    int M = A[1]-A[0];
    for (int i=2; i<N; i++)
        M = gcd(M, A[i]-A[i-1]);
    for (int i=2; i*i <= M; i++) 
        if (!(M % i)) m.push_back({i, M/i});
    if (!m.empty()) {
        for (P p: m) cout << p.i << " ";
        P p = m.back();
        if (p.i != p.j) cout << p.j << " ";
        for (int i=m.size()-2; i>=0; i--)
            cout << m[i].j << " ";   
    }
    cout << M;
    return 0;
}