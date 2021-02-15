#include <iostream>
using namespace std;

int N, K, W[100], V[100];
int m[100001];

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for (int i=0; i<N; i++)
        cin >> W[i] >> V[i];
    for (int i=0; i<N; i++) for (int k=K; k>=1; k--)
        if (W[i] <= k)
            m[k] = max(m[k], m[k-W[i]]+V[i]);
    cout << m[K];
    return 0;
}