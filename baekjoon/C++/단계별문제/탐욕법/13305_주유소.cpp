#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<int> d(N-1), c(N);
    for (int i=0; i<N-1; i++)
        cin >> d[i];
    for (int i=0; i<N; i++)
        cin >> c[i];
    int _min = INT_MAX;
    ll r = 0; 
    for (int i=0; i<N-1; i++) {
        _min = min(_min, c[i]);
        r += (ll)_min*d[i];
    }
    cout << r;
    return 0;
}