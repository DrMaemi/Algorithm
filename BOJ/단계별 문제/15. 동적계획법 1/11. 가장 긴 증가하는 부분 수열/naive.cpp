#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, ans = 0;
    int A[1000], DP[1000];

    fill(DP, DP+1000, 1);

    cin >> N;
    for (int i=0; i<N; i++)
        cin >> A[i];
    
    for (int i=1; i<N; i++) {
        for (int j=i-1; j>=0; j--) {
            if (A[j] < A[i]) {
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
    }

    cout << *max_element(DP, DP+N);
    return 0;
}