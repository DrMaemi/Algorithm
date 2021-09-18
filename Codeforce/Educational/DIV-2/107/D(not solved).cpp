#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V vector
#define PQ priority_queue
struct P { char c; int cnt; };

struct cmp {
    bool operator()(P& _1, P& _2) {
        if (_1.cnt != _2.cnt) return _1.cnt > _2.cnt;
        return _1.c > _2.c;
    }
};

int main() {
    int n, k; cin >> n >> k;
    string ans = "a";
    V<PQ<P, V<P>, cmp>> nx(k);
    for (int i=0; i<k; i++) for (char c='a'; c<'a'+k; c++) nx[i].push({c, 0});

    int loop = 0;
    V<int> visited(k);
    for (int idx=0; idx<k; idx++) {
        if (visited[idx] == loop) continue;
        ans += 'a'+idx; if (ans.size() == n) break;
        bool f = 0;
        for (int i=1; i<n; i++) {
            int j = ans[i-1]-'a';
            P p = nx[j].top(); nx[j].pop();
            ans += p.c;
            if (ans.size() == n) { f = 1; break; }
            p.cnt++; nx[j].push(p);
        }
        if (f) break;
    }
    cout << ans;
    return 0;
}