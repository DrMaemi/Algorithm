#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int N, ans = 0;
    int P[1000];

    cin >> N;
    for (int i=0; i<N; i++)
        cin >> P[i];

    sort(P, P+N);

    for (int i=1; i<=N; i++)
        ans += accumulate(P, P+i, 0);

    cout << ans;
    return 0;
}