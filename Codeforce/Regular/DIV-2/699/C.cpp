#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define V vector
#define Q deque
struct P { int i, c; };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        V<int> a(N), b(N), c(M);
        for (int i=0; i<N; i++) cin >> a[i];
        for (int i=0; i<N; i++) cin >> b[i];
        map<int, Q<int>> A, B, C;
        for (int i=0; i<N; i++) {
            Q<int> emp;
            if (a[i] == b[i]) {
                if (A.find(b[i]) == A.end()) A[b[i]] = emp;
                A[b[i]].push_back(i);
            }
            else {
                if (B.find(b[i]) == B.end()) B[b[i]] = emp;
                B[b[i]].push_back(i);
            }
        }
        for (int i=0; i<M; i++) cin >> c[i];
        if (A.find(c.back()) == A.end() && B.find(c.back()) == B.end()) {
            cout << "NO\n"; continue;
        }
        for (int i=0; i<M; i++) {
            Q<int> emp;
            if (C.find(c[i]) == C.end()) C[c[i]] = emp;
            C[c[i]].push_back(i);
        }
        bool valid = 1;
        for (auto it=B.begin(); it!=B.end(); it++) {
            auto it2 = C.find(it->first);
            if (it2 == C.end() || it2->second.size() < it->second.size()) {
                valid = 0; break;
            }
        }
        if (!valid) {
            cout << "NO\n"; continue;
        }
        V<int> r(M);
        auto it = B.find(c.back());
        if (it == B.end())
            r[M-1] = A.find(c.back())->second.back();
        else {
            r[M-1] = it->second.back();
            it->second.pop_back();
        }
        for (int i=0; i<M-1; i++) {
            auto it = B.find(c[i]);
            if (it == B.end() || it->second.empty())
                r[i] = r.back();
            else {
                r[i] = it->second.front();
                it->second.pop_front();
            }
        }
        cout << "YES\n";
        for (int x: r) cout << x+1 << " ";
        cout << "\n";
    }
    return 0;
}