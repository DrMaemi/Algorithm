#include <iostream>
using namespace std;
#define MAX 100001

int main() {
    int N, mod[MAX], len; cin >> N;
    mod[N-1] = len = N-1;
    for (int i=N-2; i>1; i--) {
        if (!mod[i+1]) mod[i] = (mod[i+2]*i)%N;
        else mod[i] = (mod[i+1]*i)%N;
        if (!mod[i]) len--;
    }
    int s;
    for (int i=2; i<N; i++)
        if (mod[i] && mod[mod[i]]) { s = i; mod[mod[i]] = 0; break; }
    cout << len-1 << "\n" << 1 << " ";
    for (int i=s; i<N; i++)
        if (mod[i]) cout << i << " ";
    return 0;
}