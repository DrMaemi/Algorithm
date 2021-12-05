// DrMaemi - 2020KB, 48ms
#include <iostream>
using namespace std;

int main() {
    int N, A[1000];

    cin >> N;
    cin >> A[0];

    for (int i=1; i<N; i++) {
        int key, j = i-1;
        
        cin >> key;

        for (; j>=0 && key<A[j]; j--) {
            A[j+1] = A[j];
        }

        A[j+1] = key;
    }

    for (int i=0; i<N; i++)
        cout << A[i] << endl;

    return 0;
}