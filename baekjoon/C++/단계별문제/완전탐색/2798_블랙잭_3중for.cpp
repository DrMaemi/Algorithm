#include <iostream>
using namespace std;

int main(void) {
    int N, M, A[300000];
    cin >> N >> M;
    for (int i=0; i<N; i++)
        cin >> A[i];
    int r = 0;
    for (int i=0; i<N-2; i++)
        for (int j=i+1; j<N-1; j++)
            for (int k=j+1; k<N; k++) {
                int sum = A[i]+A[j]+A[k];
                if (sum <= M)
                    r = max(r, sum);
            }
    cout << r;
    return 0;
}