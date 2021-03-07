#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    vector<int> MZ(K+1);
    while (N--) {
        int w, v; cin >> w >> v;
        for (int i=K; i>=w; i--)
            MZ[i] = max(MZ[i], MZ[i-w]+v);
    }
    cout << MZ[K];
    return 0;
}