#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, A[1001], M[1001][2];
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<N; i++) {
        M[i][0] = 1;
        for (int l=0; l<i; l++) {
            if (A[l] < A[i]) {
                if (!M[l][0]) M[l][0]++;
                M[i][0] = max(M[i][0], M[l][0]+1);
            }
        }
    }
    for (int i=N-1; 0<=i; i--) {
        M[i][1] = 1;
        for (int r=N-1; i<r; r--) {
            if (A[i] > A[r]) {
                if (!M[r][1]) M[r][1]++;
                M[i][1] = max(M[i][1], M[r][1]+1);
            }
        }
    }
    int answer = 0;
    for (int i=0; i<N; i++)
        answer = max(answer, M[i][0]+M[i][1]);
    cout << answer-1;
    return 0;
}