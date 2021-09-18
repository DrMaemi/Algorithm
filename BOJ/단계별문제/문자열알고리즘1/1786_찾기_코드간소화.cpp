#include <iostream>
#include <vector>
using namespace std;
#define V vector

V<int> failure_func(string& s) {
    int l = s.length();
    V<int> f(l);
    for (int i=1, j=0; i<l; i++) {
        while (j && s[i] !=s[j])
            j = f[j-1];
        if (s[i] == s[j])
            f[i] = ++j;
    }
    return f;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    string T, P;
    getline(cin, T);
    getline(cin, P);
    int tl = T.length(), pl = P.length();
    V<int> f = failure_func(P), r;
    for (int i=0, j=0; i<tl; i++) {
        while (j == pl || j && T[i] != P[j])
            j = f[j-1];
        if (T[i] == P[j]) {
            j++;
            if (j == pl)
                r.push_back(i-j+2);
        }
    }
    cout << r.size() << "\n";
    for (int i: r)
        cout << i << " ";
    return 0;
}