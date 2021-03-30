#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        map<int, int> m;
        for (int i=0; i<N; i++) {
            int x; cin >> x;
            if (m.find(x) == m.end()) m[x] = 1;
            else m[x]++;
        }
        priority_queue<int> pq;
        for (auto it=m.begin(); it!=m.end(); it++)
            pq.push(it->second);
        while (1 < pq.size()) {
            int qx = pq.top(); pq.pop();
            int qy = pq.top(); pq.pop();
            if (--qx) pq.push(qx);
            if (--qy) pq.push(qy);
        }
        if (pq.empty()) cout << 0 << "\n";
        else cout << pq.top() << "\n";
    }
    return 0;
}