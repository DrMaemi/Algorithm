#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int m[1002][1002];

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " "+s1; s2 = " "+s2;
    for (int i=1; i<s1.length(); i++)
        for (int j=1; j<s2.length(); j++) {
            if (s1[i] == s2[j])
                m[i][j] = m[i-1][j-1]+1;
            else
                m[i][j] = max(m[i][j-1], m[i-1][j]);
        }
    cout << m[s1.length()-1][s2.length()-1];
    return 0;
}