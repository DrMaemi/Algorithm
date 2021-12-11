#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    int A[501], DP[501] = {0};

    cin >> N;
    for (int i=0; i<N; i++) {
        int a, b;

        cin >> a >> b;
        A[a] = b;
        DP[a] = 1;
    }

    for (int i=1; i<=500; i++)
        if (DP[i])
            for (int j=i-1; j>=0; j--)
                if (DP[j] && A[j] < A[i])
                    DP[i] = max(DP[i], DP[j]+1);

    cout << N-*max_element(DP, DP+501);
    return 0;
}