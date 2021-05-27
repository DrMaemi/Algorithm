#include <iostream>
#include <vector>
using namespace std;
#define V vector

V<int> failure_func(string& S) {
    int n = S.length();
    V<int> f(n);
    int i = 1, j = 0;
    while (i+j < n)
        if (S[i+j] == S[j]) {
            j++;
            f[i+j-1] = j;
        }
        else if (!j)
            i++;
        else {
            i += j-f[j-1];
            j = f[j-1];
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
    int i = 0, j = 0;
    while (i <= tl-pl)
        if (j < pl && T[i+j] == P[j]) {
            j++;
            if (j == pl)
                r.push_back(i+1);
        }
        else if (!j)
            i++;
        else {
            i += j-f[j-1];
            j = f[j-1];
        }
    cout << r.size() << "\n";
    for (int i: r)
        cout << i << " ";
    return 0;
}