#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i=0; i<N; i++)
        cin >> A[i];
    int l = 0, r = 0, sum = 0, ans = N+1;
    while (1)
        if (S <= sum) {
            ans = min(ans, r-l);
            sum -= A[l++];
        }
        else if (r == N)
            break;
        else
            sum += A[r++];
    cout << (ans == N+1? 0: ans);
    return 0;
}