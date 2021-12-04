// DrMaemi - 1712ms, 2020KB
#include <iostream>
using namespace std;

#define MAX 15

int N, ans = 0;
bool c[MAX], d1[2*MAX-1], d2[2*MAX-1];

void f(int i) {
    if (i == N) {
        ans++;
        return;
    }

    for (int j=0; j<N; j++) {
        if (!c[j] && !d1[i+j] && !d2[N-i+j-1]) {
            c[j] = d1[i+j] = d2[N-i+j-1] = 1;
            f(i+1);
            c[j] = d1[i+j] = d2[N-i+j-1] = 0;
        }
    }
}

int main() {
    cin >> N;
    f(0);
    cout << ans;
    return 0;
}