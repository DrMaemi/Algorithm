#include <iostream>
#include <vector>
using namespace std;
#define V vector

int main() {
    int N; cin >> N;
    V<int> A(N);
    for (int i=0; i<N; i++)
        cin >> A[i];
    int _max = 0;
    for (int start=0; start<3; start++) {
        V<bool> v(N, 0);
        v[start] = 1;
        int nx = start+A[start], r = 1;
        while (!v[nx]) {
            v[nx] = 1; r++;
            nx += A[nx];
        }
        r++;
        _max = max(_max, r);
    }
    cout << _max;
    return 0;
}