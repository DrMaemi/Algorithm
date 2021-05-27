#include <iostream>
#include <algorithm>
using namespace std;
#define s string

bool compare(s _1, s _2) {
    if (_1.size() != _2.size())
        return _1.size() < _2.size();
    return _1 < _2;
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    s S[20000];
    for (int i=0; i<N; i++)
        cin >> S[i];
    sort(S, S+N, compare);
    cout << S[0] << "\n";
    s pre = S[0];
    for (int i=1; i<N; i++) {
        if (pre != S[i])
            cout << S[i] << "\n";
        pre = S[i];
    }
    return 0;
}