#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N, S = 0; cin >> N;
    int* A = (int*)malloc(sizeof(int)*N);
    int* B = (int*)malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N; i++) cin >> B[i];
    sort(A, A+N); sort(B, B+N, greater<>());
    for (int i=0; i<N; i++) S += A[i]*B[i];
    cout << S;
    return 0;
}