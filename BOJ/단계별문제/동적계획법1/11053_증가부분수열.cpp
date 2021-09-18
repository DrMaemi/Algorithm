#include <iostream>
#include <algorithm>
using namespace std;

int N, A[1001], m[1001];

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    int answer = 1;
    for (int i=1; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (A[j] < A[i]) {
                if (!m[j]) m[j]++;
                m[i] = max(m[i], m[j]+1);
            }
        }
        answer = max(answer, m[i]);
    }
    cout << answer;
    return 0;
}