#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    int P[301] = {0};
    int DP[301] = {0};

    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> P[i];

    DP[1] = P[1];
    DP[2] = P[1]+P[2];

    for (int i=3; i<=N; i++)
        DP[i] = max(DP[i-3]+P[i-1]+P[i], DP[i-2]+P[i]);

    cout << DP[N];
    return 0;
}