#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int N;
    int DP[100][10] = {0};
    const int mod = 1e9;

    cin >> N;
    fill(&DP[0][1], &DP[99][10], 1);
    for (int n=1; n<N; n++) {
        DP[n][0] = DP[n-1][1];
        DP[n][9] = DP[n-1][8];

        for (int i=1; i<9; i++)
            DP[n][i] = (DP[n-1][i-1]+DP[n-1][i+1])%mod;
    }

    cout << accumulate(DP[N-1], DP[N-1]+10, 0,
        [](const int& a, const int& b) {
            return (a+b)%mod;
        }
    );
    return 0;
}