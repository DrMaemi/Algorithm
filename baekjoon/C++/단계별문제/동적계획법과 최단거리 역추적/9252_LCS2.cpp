#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define S string
#define V vector

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    S s1, s2;
    cin >> s1 >> s2;
    s1 = " "+s1; s2 = " "+s2;
    int _i = s1.length(), _j = s2.length();
    V<V<int>> m(_i);
    for(int i=0; i<_i; i++)
        m[i].resize(_j, 0);
    for (int i=1; i<_i; i++)
        for (int j=1; j<_j; j++)
            if (s1[i] == s2[j])
                m[i][j] = m[i-1][j-1]+1;
            else
                m[i][j] = max(m[i-1][j], m[i][j-1]);
    cout << m[_i-1][_j-1] << "\n";
    S out;
    for (int i=_i-1, j=_j-1; i && j;) {
        if (m[i][j] == m[i-1][j])
            i--;
        else if (m[i][j] == m[i][j-1])
            j--;
        else {
            out.push_back(s2[j]);
            i--; j--;
        }
    }
    for (auto it=out.rbegin(); it!=out.rend(); it++)
        cout << *it;
    return 0;
}