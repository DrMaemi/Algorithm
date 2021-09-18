#include <iostream>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    bool odd = 0;
    if (N%2) odd = 1;
    if ((!odd && N%6 != 2) || (odd && (N-1)%6 != 2)) {
        if (odd) N--;
        for (int i=1; i<=N/2; i++)
            cout << 2*i << "\n";
        for (int i=1; i<=N/2; i++)
            cout << 2*i-1 << "\n";
        if (odd) cout << N+1 << "\n";
    }
    else if ((!odd && N/6 != 0) || (odd && (N-1)/6 != 2)) {
        if (odd) N--;
        for (int i=1; i<=N/2; i++)
            cout << 1+(2*i+N/2-3)%N << "\n";
        for (int i=N/2; i; i--)
            cout << N-(2*i+N/2-3)%N << "\n";
        if (odd) cout << N+1 << "\n";
    }
    return 0;
}