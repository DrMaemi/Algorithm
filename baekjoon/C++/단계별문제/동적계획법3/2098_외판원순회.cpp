#include <iostream>
#include <vector>
using namespace std;
#define V vector
#define MAX 1000000

int N;
V<V<int>> W, CM;

int dp(int bit, int last) {
    if (bit == (1 << N)-1) return W[last][0];
    if (CM[last][bit] == N*MAX)
        for (int j=0; j<N; j++)
            if (!(bit & (1 << j)))
                CM[last][bit] = min(CM[last][bit], W[last][j]+dp(bit | (1 << j), j));
    return CM[last][bit];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    W.resize(N, V<int>(N));
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        cin >> W[i][j];
        if (!W[i][j]) W[i][j] = MAX;
    }
    CM.resize(N, V<int>(1 << N, N*MAX));
    cout << dp(1, 0);
    return 0;
}