#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MAX 1000000000
typedef long long ll;
struct P { int n, cnt; };
struct PP { int n, d; };

bool cmp(P& _1, P& _2) { return _1.cnt > _2.cnt; }
bool cmpp(PP& _1, PP& _2) { return _1.d < _2.d; }

int main() {
    int N; cin >> N;
    map<int, int> m;
    for (int i=0; i<N; i++) {
        int n; cin >> n;
        if (m.find(n) == m.end()) m[n] = 1;
        else m[n]++;
    }
    vector<P> V;
    for (auto it=m.begin(); it!=m.end(); it++)
        V.push_back({it->first, it->second});
    sort(V.begin(), V.end(), cmp);
    ll ans = 0; int i = 0, _max = -1, _min = -1;
    while (i < V.size()) {
        int cnt = V[i].cnt;
        vector<int> vv(1, V[i++].n);
        while (i < V.size())
            if (V[i].cnt != cnt) break;
            else vv.push_back(V[i++].n);
        sort(vv.begin(), vv.end());
        
        vector<PP> vvv;
        for (int x: vv) {
            int d = x > _max? x-_max: 0 + x < _min? _min-x: 0;
            vvv.push_back({x, d});
        }
        sort(vvv.begin(), vvv.end(), cmpp);
        for (PP pp: vvv) cout << pp.n << " ";
        if (_max == -1) { _max = _min = vvv[0].n; }
        for (PP pp: vvv) { 
            _max = max(_max, pp.n); _min = min(_min, pp.n);
            ans += (_max-_min)*cnt;
        }
    }
    cout << ans << "\n";
    return 0;
}