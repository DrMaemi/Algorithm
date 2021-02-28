#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> S;

int P(int i) {
    if (S[i] == i) return i;
    return S[i] = P(S[i]);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    S.resize(N+1);
    for (int i=0; i<=N; i++)
        S[i] = i;
    while (M--) {
        int k, u, v;
        cin >> k >> u >> v;
        if (k) {
            if (P(u) == P(v))
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        S[P(u)] = P(v);
    }
    return 0;
}