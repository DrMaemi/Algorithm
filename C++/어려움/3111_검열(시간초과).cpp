#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V vector

V<int> failure_func(string& s) {
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
    string _A, _T, A, T;
    cin >> _A >> _T;
    A = _A; reverse(_A.begin(), _A.end());
    T = _T; reverse(_T.begin(), _T.end());
    V<int> ff = failure_func(A);
    int i, j, Tl, Al = A.length();
    bool f;
    while (1) {
        Tl = T.length();
        i = j = 0;
        f = 0;
        while (i+j < Tl)
            if (T[i+j] == A[j]) {
                j++;
                if (j == Al) {
                    T.erase(i, j);
                    _T.erase(Tl-j, Tl-i);
                    f = 1; break;
                }
            }
            else if (!j)
                i++;
            else {
                i += j-ff[j-1];
                j = ff[j-1];
            }
        if (!f) break;
        Tl = _T.length();
        i = j = 0;
        f = 0;
        while (i+j < Tl)
            if (_T[i+j] == _A[j]) {
                j++;
                if (j == Al) {
                    _T.erase(i, j);
                    T.erase(Tl-j, Tl-i);
                    f = 1; break;
                }
            }
            else if (!j)
                i++;
            else {
                i += f-ff[f-1];
                f = ff[j-1];
            }
        if (!f) break;
    }
    cout << T;
    return 0;
}