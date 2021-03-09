#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int D, N;
    cin >> D >> N;
    vector<int> O(D);
    int _min = INT_MAX;
    for (int i=0; i<D; i++) {
        cin >> O[i];
        if (O[i] < _min)
            _min = O[i];
        else
            O[i] = _min;
    }
    queue<int> P;
    for (int i=0; i<N; i++) {
        int n; cin >> n;
        P.push(n);
    }
    int depth = D-1;
    for (; depth>=0; depth--) {
        if (P.front() <= O[depth])
            P.pop();
        if (P.empty())
            break;
    }
    cout << (P.empty()? depth+1: 0);
    return 0;
}