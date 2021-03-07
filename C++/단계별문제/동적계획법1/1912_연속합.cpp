#include <iostream>
using namespace std;

int N, S[100001], m[100001];

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> S[i];
        m[i] = S[i];
    }
    int _max = S[0];
    for (int i=1; i<N; i++) {
        m[i] = max(m[i], m[i-1]+S[i]);
        _max = max(_max, m[i]);
    }
    cout << _max;
    return 0;
}