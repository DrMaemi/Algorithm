#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define V vector
#define S string
struct P { V<int> n; V<char> o; };

int to_int(S s) {
    int r = 0;
    for (int i=s.length()-1, p=0; i>=0; i--, p++)
        r += (s[i]-'0')*pow(10, p);
    return r;
}

P split(S s) {
    P r; int f = -1;
    for (int i=0; i<s.length(); i++)
        if (s[i] == '-' || s[i] == '+') {
            r.n.push_back(to_int(s.substr(f+1, i-f-1)));
            r.o.push_back(s[i]);
            f = i;
        }
    r.n.push_back(to_int(s.substr(f+1)));
    return r;
}

int main() {
    S s; cin >> s;
    P p = split(s);
    int r = p.n[0]; bool f = 0;
    for (int i=0; i<p.o.size(); i++) {
        if (f) r -= p.n[i+1];
        else if (p.o[i] == '-') {
            r -= p.n[i+1];
            f = 1;
        }
        else r += p.n[i+1];
    }
    cout << r;
    return 0;
}