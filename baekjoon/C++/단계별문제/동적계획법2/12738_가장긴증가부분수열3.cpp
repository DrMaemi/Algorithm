#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N), lis;
    for (int i=0; i<N; i++)
        cin >> A[i];
    lis.push_back(A[0]);
    for (int i=1; i<N; i++)
        if (lis.back() < A[i])
            lis.push_back(A[i]);
        else
            *lower_bound(lis.begin(), lis.end(), A[i]) = A[i];
    cout << lis.size();
    return 0;
}