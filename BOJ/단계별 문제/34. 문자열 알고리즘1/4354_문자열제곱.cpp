#include <iostream>
#include <vector>
using namespace std;
#define V vector

V<int> failure_func(string& s) {
    int l = s.length();
    V<int> f(l);
    int j = 0;
    for (int i=1; i<l; i++) {
        while (j && s[i] != s[j])
            j = f[j-1];
        if (s[i] == s[j])
            f[i] = ++j;
    }
    return f;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    string s;
    while (1) {
        getline(cin, s);
        if (s == ".") break;
        int l = s.length();
        V<int> f = failure_func(s);
        if (!f[l-1] || f[l-1]%(l-f[l-1]))
            cout << 1 << "\n";
        else
            cout << f[l-1]/(l-f[l-1])+1 << "\n";
    }
    return 0;
}