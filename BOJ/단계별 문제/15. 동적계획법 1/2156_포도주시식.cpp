#include <iostream>
#include <algorithm>
using namespace std;

int N;
int wines[10000];
int m[10000];

int solve() {
    m[0] = wines[0]; m[1] = wines[0]+wines[1];
    for (int i=2; i<N; i++)
        m[i] = max(max(m[i-1], m[i-2]+wines[i]), m[i-3]+wines[i-1]+wines[i]);
    return m[N-1];
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) cin >> wines[i];
    cout << solve();
    return 0;
}