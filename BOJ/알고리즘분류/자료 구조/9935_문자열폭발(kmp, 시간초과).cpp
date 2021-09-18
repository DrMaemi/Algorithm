#include <iostream>
#include <vector>
using namespace std;
#define V vector
#define S string

V<int> failure_func(S& s) {
    int l = s.length();
    V<int> f(l);
    for (int i=1, j=0; i<l; i++) {
        while (j && s[i] != s[j])
            j = f[j-1];
        if (s[i] == s[j])
            f[i] = ++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    S T, P; cin >> T >> P;
    V<int> f = failure_func(P);
    int Tl = T.length(), Pl = P.length();
    int i = 0, j = 0;
    while (i <= Tl-Pl) {
        if (T[i+j] == P[j]) {
            j++;
            if (j == Pl) {
                auto s = T.begin()+i;
                T.erase(s, s+Pl);
                i = i-Pl > 0? i-Pl+1: 0; j = 0;
                Tl -= Pl;
            }
        }
        else if (!j) i++;
        else {
            i += j-f[j-1];
            j = f[j-1];
        }
    }
    if (T.empty()) cout << "FRULA";
    else cout << T;
    return 0;
}