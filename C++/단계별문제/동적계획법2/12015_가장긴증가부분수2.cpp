#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> v;
    int n; cin >> n;
    v.push_back(n);
    for (int i=1; i<N; i++) {
        cin >> n;
        if (v.back() < n)
            v.push_back(n);
        else {
            auto it = lower_bound(v.begin(), v.end(), n);
            *it = n;
        }
    }
    cout << v.size();
    return 0;
}