#include <iostream>
#include <vector>
using namespace std;
#define V vector

int main() {
    int N; cin >> N;
    V<int> A;
    V<bool> check(N+1, 1);
    for (int i=2; i*i<=N; i++)
        if (check[i])
            for (int j=i*i; j<=N; j+=i)
                check[j] = 0;
    for (int i=2; i<=N; i++)
        if (check[i])
            A.push_back(i);
    int ans = 0, sum = 0, l = 0, r = 0;
    while (1) {
        if (N <= sum)
            sum -= A[l++];
        else if (r == A.size())
            break;
        else
            sum += A[r++];
        if (sum == N)
            ans++;
    }
    cout << ans;
    return 0;
}