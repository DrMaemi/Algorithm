#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        if ((N-1)/2 < K) { cout << -1 << "\n"; continue; }
        vector<int> ans;
        int l = 1, r = N;
        for (int i=0; i<K; i++) { ans.push_back(l++); ans.push_back(r--); }
        for (int i=0; i<N-2*K; i++) { ans.push_back(l++); }
        for (int x: ans) cout << x << " "; cout << "\n";
    }
    return 0;
}