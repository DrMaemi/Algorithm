#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    int A[100000];
    for (int i=0; i<N; i++)
        cin >> A[i];
    sort(A, A+N);
    int s = INT_MAX;
    int l = 0, a1 = A[l];
    int r = N-1, a2 = A[r];
    while (l < r) {
        int _s = A[l]+A[r];
        if (abs(_s) < s) {
            s = abs(_s);
            a1 = A[l]; a2 = A[r];
        }
        if (_s < 0) l++;
        else r--;
    }
    cout << a1 << " " << a2;
    return 0;
}