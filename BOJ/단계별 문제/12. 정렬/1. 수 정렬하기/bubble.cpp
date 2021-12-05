// DrMaemi - 2020KB, 40ms
#include <iostream>
using namespace std;

int main() {
    int N, A[1000];

    cin >> N;

    for (int i=0; i<N; i++)
        cin >> A[i];

    for (int i=0; i<N; i++) {
        bool sorted = 1;

        for (int j=0; j<N-1-i; j++) {
            if (A[j] > A[j+1]) {
                int tmp = A[j];

                A[j] = A[j+1];
                A[j+1] = tmp;
                sorted = 0;
            }
        }

        if (sorted)
            break;
    }

    for (int i=0; i<N; i++)
        cout << A[i] << endl;
    
    return 0;
}