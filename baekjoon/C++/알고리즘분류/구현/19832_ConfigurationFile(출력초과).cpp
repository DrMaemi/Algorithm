#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
#define S string
#define V vector
struct P { int v, o; };

int cnt = 0;
map<S, stack<P>> m;

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

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    S s;
    while (cin >> s) {
        if (s == "{") cnt++;
        else if (s == "}") cnt--;
        else {
            V<S> sp = split(s);
            if (!is_in_map(sp[0])) {
                m[sp[0]] = stack<P>();
                m[sp[0]].push({0, cnt});
            }
            while (m[sp[0]].top().o > cnt) {
                m[sp[0]].pop();
                if (m[sp[0]].empty())
                    m[sp[0]].push({0, cnt});
            }
            if (sp[0] == sp[1])
                cout << m[sp[0]].top().v << "\n";
            else {
                if (m[sp[0]].top().o != cnt)
                    m[sp[0]].push({0, cnt});
                if (is_string(sp[1])) {
                    if (!is_in_map(sp[1])) {
                        m[sp[1]] = stack<P>();
                        m[sp[1]].push({0, cnt});
                    }
                    while (m[sp[1]].top().o > cnt) {
                        m[sp[1]].pop();
                        if (m[sp[1]].empty())
                            m[sp[1]].push({0, cnt});
                    }
                    m[sp[0]].top().v = m[sp[1]].top().v;
                    cout << m[sp[0]].top().v << "\n";
                }
                else 
                    m[sp[0]].top().v = stoi(sp[1]);
            }
        }
    }
    return 0;
}