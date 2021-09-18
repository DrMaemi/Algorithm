#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q, t; cin >> N >> Q;
    vector<int> a(51);
    for (int i=1; i<=N; i++) { cin >> t; if (!a[t]) a[t] = i; }
    while (Q--) {
        cin >> t; int& ans = a[t]; cout << ans << " ";
        for (t=1; t<=50; t++) if (a[t] < ans) a[t]++;
        ans = 1;
    }
    return 0;
}