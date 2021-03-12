#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MIN -1000000000
#define MAX 1000000000
struct P { int l, r; };

bool cmp(P& _1, P& _2) {
    if (_1.l != _2.l)
        return _1.l < _2.l;
    return _1.r < _2.r;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<P> lines(N);
    for (int i=0; i<N; i++)
        cin >> lines[i].l >> lines[i].r;
    sort(lines.begin(), lines.end(), cmp);
    int l = lines[0].l, r = lines[0].r;
    int ans = 0;
    for (P line: lines) {
        if (r < line.l) {
            ans += r-l;
            l = line.l;
        }
        r = max(r, line.r);
    }
    ans += r-l;
    cout << ans;
    return 0;
}