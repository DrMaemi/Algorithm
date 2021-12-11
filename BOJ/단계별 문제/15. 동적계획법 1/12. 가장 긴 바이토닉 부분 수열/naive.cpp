#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, ans = 0;
    int A[1000], L[1000] = {0}, R[1000] = {0};

    cin >> N;
    for (int i=0; i<N; i++)
        cin >> A[i];

    for (int i=1; i<N;i ++)
        for (int j=i-1; j>=0; j--)
            if (A[j] < A[i])
                L[i] = max(L[i], L[j]+1);

    for (int i=N-2; i>=0; i--)
        for (int j=i+1; j<N; j++)
            if (A[i] > A[j])
                R[i] = max(R[i], R[j]+1);

    for (int i=0; i<N; i++)
        ans = max(ans, L[i]+R[i]);

    cout << ans+1;
    return 0;
}