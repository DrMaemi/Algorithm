#include <iostream>
using namespace std;
#define MAX 100001

int main() {
    int N, mod[MAX]; cin >> N;
    mod[N-1] = N-1;
    for (int i=N-2; i>1; i--) {
        if (!mod[i+1]) mod[i] = (mod[i+2]*i)%N;
        else mod[i] = (mod[i+1]*i)%N;
    }
    for (int i=2; i<N; i++) {

    }
    return 0;
}