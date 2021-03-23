#include <iostream>
#include <queue>
using namespace std;
#define S string
typedef long long ll;
struct P { deque<ll> n; deque<char> o; };

deque<ll> n;
deque<char> o;

P split(S& s) {
    P r;
    int start = s[0] == '-'? 1: 0;
    int p = start;
    for (int i=start+1; i<s.length(); i++)
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            r.n.push_back(stoll(s.substr(p, i-p)));
            r.o.push_back(s[i]);
            p = ++i;
        }
    r.n.push_back(stoll(s.substr(p)));
    r.n[0] *= start? -1: 1;
    return r;
}

int order(char op) {
    if (op == '*' || op == '/') return 1;
    return 2;
}

ll cal(int i, char op) {
    if (op == '+') return n[i]+n[i+1];
    else if (op == '-') return n[i]-n[i+1];
    else if (op == '*') return n[i]*n[i+1];
    else return n[i]/n[i+1];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    S s; cin >> s;
    P splited = split(s);
    n = splited.n;
    o = splited.o;
    while (!o.empty()) {
        char o1 = o.front(), o2 = o.back();
        ll r1 = cal(0, o1), r2 = cal(o.size()-1, o2);
        bool f;
        if (order(o1) != order(o2)) f = order(o1) < order(o2);
        else f = r1 >= r2;
        if (f) {
            o.pop_front();
            n.pop_front(); n.pop_front();
            n.push_front(r1);
        }
        else {
            o.pop_back();
            n.pop_back(); n.pop_back();
            n.push_back(r2);
        }
    }
    cout << n[0];
    return 0;
}