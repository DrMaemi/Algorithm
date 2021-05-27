#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string s1 = "a"+s;
        string s2 = s+"a";
        string s3 = s1, s4 = s2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        if (s1 != s3) cout << "YES\n" << s3 << "\n";
        else if (s2 != s4) cout << "YES\n" << s4 << "\n";
        else cout << "NO\n";
    }
    return 0;
}