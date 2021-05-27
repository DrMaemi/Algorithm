#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define V vector

int main() {
    int N; cin >> N;
    V<int> S(N);
    for (int i=0; i<N; i++)
        cin >> S[i];

    V<int> ls(N), rs(N);
    V<int> lp(N, -1), rp(N, -1);
    V<int> lv, lvi, rv, rvi;

    lv.push_back(S[0]); lvi.push_back(0);
    for (int i=1; i<N; i++) {
        if (lv.back() < S[i]) {
            lv.push_back(S[i]);
            lp[i] = lvi.back();
            lvi.push_back(i);
            ls[i] = lv.size();
        }
        else {
            auto it = lower_bound(lv.begin(), lv.end(), S[i]);
            *it = S[i];
            int idx = it-lv.begin();
            lvi[idx] = i;
            if (idx) lp[i] = lvi[idx-1];
            ls[i] = idx+1;
        }
    }
    rv.push_back(S[N-1]); rvi.push_back(N-1);
    for (int i=N-2; i>=0; i--) {
        if (rv.back() < S[i]) {
            rv.push_back(S[i]);
            rp[i] = rvi.back();
            rvi.push_back(i);
            rs[i] = rv.size();
        }
        else {
            auto it = lower_bound(rv.begin(), rv.end(), S[i]);
            *it = S[i];
            int idx = it-rv.begin();
            rvi[idx] = i;
            if (idx) rp[i] = rvi[idx-1];
            rs[i] = idx+1;
        }
    }
    int _max = 0, start;
    for (int i=0; i<N; i++) {
        int s = ls[i]+rs[i];
        if (_max < s) {
            _max = s;
            start = i;
        }
    }
    cout << _max-1 << "\n";
    stack<int> out;
    out.push(start);
    for (int i=start; lp[i]!=-1; i=lp[i])
        out.push(lp[i]);
    while (!out.empty()) {
        cout << S[out.top()] << " ";
        out.pop();
    }
    for (int i=start; rp[i]!=-1; i=rp[i])
        cout << S[rp[i]] << " ";
    return 0;
}