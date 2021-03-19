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
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    string _A, A, T;
    cin >> _A >> T;
    A = _A; reverse(_A.begin(), _A.end());
    V<int> f = failure_func(A), _f = failure_func(_A);
    int Tl, Al = A.length();
    int l = 0, r = T.size()-1;
    bool found = 0;
    while (l <= r) {
        Tl = T.length();
        int i = l, j = 0;
        found = 0;
        while (i+j < Tl)
            if (T[i+j] == A[j]) {
                j++;
                if (j == Al) {
                    T.erase(i, Al);
                    l = i-Al+1 > 0? i-Al+1: 0; r -= Al;
                    found = 1; break;
                }
            }
            else if (!j)
                i++;
            else {
                i += j-f[j-1];
                j = f[j-1];
                l = i;
            }
        if (!found) break;
        i = r, j = 0;
        found = 0;
        while (i-j >= 0)
            if (T[i-j] == A[j]) {
                j++;
                if (j == Al) {
                    T.erase(i-Al+1, Al);
                    int end = T.length()-1;
                    r = i+Al-1 > end? end: i+Al-1;
                    found = 1; break;
                }
            }
            else if (!j)
                i--;
            else {
                i -= j-f[j-1];
                j = f[j-1];
                r = i;
            }
        if (!found) break;
    }
    cout << T;
    return 0;
}