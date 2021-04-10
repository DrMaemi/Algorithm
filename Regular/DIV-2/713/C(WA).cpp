#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        vector<int> r(2); cin >> r[0] >> r[1];
        int n = r[0]+r[1];
        string s; cin >> s;
        bool valid = 1;
        for (char c: s) if (c == '0') r[0]--; else if (c == '1') r[1]--;
        if (r[0] < 0 || r[1] < 0) valid = 0;
        else if (n & 1) {
            for (int i=0; i<n/2; i++) {
                int j = n-i-1;
                if (s[i] == '?' && s[j] == '?') {
                    s[i] = s[j] = r[0] < r[1]? '1': '0';
                    r[s[i]-'0'] -= 2;
                }
                else if (s[i] == '?' && s[j] != '?') {
                    s[i] = s[j];
                    r[s[i]-'0']--;
                }
                else if (s[i] != '?' && s[j] == '?') {
                    s[j] = s[i];
                    r[s[j]-'0']--;
                }
                if (s[i] != s[j] || (r[0] < 0 || r[1] < 0)) { valid = 0; break; }
            }
            if (valid) {
                if (s[n/2] == '?') {
                    s[n/2] = r[0]? '0': '1';
                    if (s[n/2] == '0') r[0]--; else r[1]--;
                }
                if (r[0] < 0 || r[1] < 0) valid = 0;
            }
        }
        else {
            for (int i=0; i<n/2; i++) {
                int j = n-i-1;
                if (s[i] == '?' && s[j] == '?') {
                    s[i] = s[j] = r[0] < r[1]? '1': '0';
                    r[s[i]-'0'] -= 2;
                }
                else if (s[i] == '?' && s[j] != '?') {
                    s[i] = s[j];
                    r[s[i]-'0']--;
                }
                else if (s[i] != '?' && s[j] == '?') {
                    s[j] = s[i];
                    r[s[j]-'0']--;
                }
                if (s[i] != s[j] || (r[0] < 0 || r[1] < 0)) { valid = 0; break; }
            }
        }
        if (valid) cout << s << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}