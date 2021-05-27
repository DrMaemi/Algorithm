#include <iostream>
#include <algorithm>
using namespace std;
struct M {
    int s, e;
};

int N;
M A[100000];

bool compare(M _1, M _2) {
    if (_1.e != _2.e) return _1.e < _2.e;
    return _1.s < _2.s;
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> A[i].s >> A[i].e;
    sort(A, A+N, compare);
    int cur = 0, r = 0;
    for (int i=0; i<N; i++) if (cur <= A[i].s) {
        cur = A[i].e;
        r++;
    }
    cout << r;
    return 0;
}