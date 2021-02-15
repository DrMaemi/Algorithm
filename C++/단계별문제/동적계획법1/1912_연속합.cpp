#include <iostream>
using namespace std;

int N, I[100001], m[100001];

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> I[i];
    for (int i=0; i<N; i++) m[i] = I[i];
    int sum = I[0];
    for (int i=1; i<N; i++) {
        m[i] = max(m[i], m[i-1]+I[i]);
        sum = max(sum, m[i]);
    }
    cout << sum;
    return 0;
}