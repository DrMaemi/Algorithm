#include <iostream>
using namespace std;

int N, M;
int A[300000];
int r = 0;

void solve(int d, int p, int s) {
    if (d == 3) {
        if (s <= M)
            r = max(r, s);
        return;
    }
    for (int i=p; i<N-2+d; i++)
        solve(d+1, i+1, s+A[i]);
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i=0; i<N; i++)
        cin >> A[i];
    solve(0, 0, 0);
    cout << r;
    return 0;
}