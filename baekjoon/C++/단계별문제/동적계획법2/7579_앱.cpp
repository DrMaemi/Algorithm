#include <iostream>
#include <vector>
using namespace std;
#define V vector
struct App { int m, c; };

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    V<App> A(N);
    for (int i=0; i<N; i++)
        cin >> A[i].m;
    int cs = 0;
    for (int i=0; i<N; i++) {
        cin >> A[i].c;
        cs += A[i].c;
    }
    V<int> CM(cs+1);
    for (App a: A)
        for (int i=cs; i>=a.c; i--)
            CM[i] = max(CM[i], CM[i-a.c]+a.m);
    for (int i=0; i<=cs; i++)
        if (CM[i] >= M) {
            cout << i;
            break;
        }
    return 0;
}