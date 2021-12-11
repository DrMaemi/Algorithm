#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;

    cin >> N >> K;

    vector<int> DP(K+1);

    for (int i=0; i<N; i++) {
        int w, v;

        cin >> w >> v;
        for (int used=K; used>=w; used--)
            DP[used] = max(DP[used], DP[used-w]+v);
    }

    cout << DP[K];
    return 0;
}