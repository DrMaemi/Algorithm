#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int s, e; };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, ans = 0, cur = 0;
    vector<P> v;

    cin >> N;

    for (int i=0; i<N; i++) {
        int s, e;

        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), [](const P& a, const P& b){
        if (a.e != b.e)
            return a.e < b.e;

        return a.s < b.s;
    });

    for (P p: v) {
        if (cur <= p.s) {
            ans++;
            cur = p.e;
        }
    }

    cout << ans;
    return 0;
}