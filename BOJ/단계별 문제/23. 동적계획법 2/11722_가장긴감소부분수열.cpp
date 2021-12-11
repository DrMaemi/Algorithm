#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    V<int> A(N), lds;
    for (int i=0; i<N; i++)
        cin >> A[i];
    lds.push_back(A[0]);
    for (int i=1; i<N; i++)
        if (A[i] < lds.back())
            lds.push_back(A[i]);
        else {
            auto it = lower_bound(lds.begin(), lds.end(), A[i], greater<int>());
            *it = A[i];
        }
    cout << lds.size();
    return 0;
}