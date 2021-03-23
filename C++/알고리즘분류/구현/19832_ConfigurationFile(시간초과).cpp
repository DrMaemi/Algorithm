#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
#define S string
#define V vector
#define FORINMAP for(auto it=m.begin();it!=m.end();it++)

int cnt = 1;
map<S, stack<int>> m;

V<S> split(S& s) {
    V<S> r(2);
    for (int i=0; i<s.length(); i++)
        if (s[i] == '=') {
            r[0] = s.substr(0, i);
            r[1] = s.substr(i+1);
        }
    return r;
}

bool is_string(S& s) {
    if ('a' <= s[0] && s[0] <= 'z') return 1;
    return 0;
}

bool is_in_map(S& s) {
    if (m.find(s) == m.end()) return 0;
    return 1;
}

void span0(S& s) {
    m[s] = stack<int>();
    for (int i=0; i<cnt; i++)
        m[s].push(0);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    S s;
    while (cin >> s) {
        if (s == "{") {
            cnt++;
            FORINMAP {
                stack<int>& stk = it->second;
                int d = cnt-stk.size();
                while (d--) stk.push(stk.top());
            }
        }
        else if (s == "}") {
            cnt--;
            FORINMAP {
                stack<int>& stk = it->second;
                stk.pop();
            }
        }
        else {
            V<S> sp = split(s);
            if (!is_in_map(sp[0])) span0(sp[0]);
            int& t = m[sp[0]].top();
            if (is_string(sp[1])) {
                if (!is_in_map(sp[1])) span0(sp[1]);
                t = m[sp[1]].top();
                cout << t << "\n";
            }
            else t = stoi(sp[1]);
        }
    }
    return 0;
}