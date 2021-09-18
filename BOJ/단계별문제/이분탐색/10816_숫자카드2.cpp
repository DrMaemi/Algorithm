#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> S(N);
    for (int i=0; i<N; i++)
        cin >> S[i];
    sort(S.begin(), S.end());
    int M; cin >> M;
    while (M--) {
        int n; cin >> n;
        int l = lower_bound(S.begin(), S.end(), n)-S.begin();
        int r = upper_bound(S.begin(), S.end(), n)-S.begin();
        cout << r-l << " ";
    }
    return 0;
}