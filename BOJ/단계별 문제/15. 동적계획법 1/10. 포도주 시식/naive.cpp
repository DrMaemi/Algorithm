#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int W[10001] = {0}, DP[10001] = {0};

    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> W[i];

    DP[1] = W[1];
    DP[2] = W[1]+W[2];

    for (int i=3; i<=N; i++) {
        int tmp[3] = {DP[i-3]+W[i-1]+W[i], DP[i-2]+W[i], DP[i-1]};
        DP[i] = *max_element(tmp, tmp+3);
    }

    cout << DP[N];
    return 0;
}