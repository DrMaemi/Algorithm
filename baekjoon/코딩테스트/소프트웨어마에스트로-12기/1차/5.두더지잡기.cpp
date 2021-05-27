#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    int _max = 0;
    vector<queue<int>> vq(N*N+1);
    for (int i=1; i<=N*N; i++) {
        int K; cin >> K >> K;
        while (K--) {
            int T; cin >> T;
            vq[i].push(T);
            _max = max(_max, T);
        }
    }
    int r = 0;
    for (int T=1; T<=_max; T++) {
        int _i = 0;
        for (int i=1; i<vq.size(); i++) {
            int t = vq[i].front();
            if (t == T) {
                vq[i].pop(); _i = i;
            }
        }
        r += _i;
    }
    cout << r;
    return 0;
}