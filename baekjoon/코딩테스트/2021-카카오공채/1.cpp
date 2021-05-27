#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string ans = "";
    for (int p=0; p<s.length(); p++) {
        if ('0' <= s[p] && s[p] <= '9') ans += s[p];
        else if (s[p] == 'z') { ans += '0'; p += 3; }
        else if (s[p] == 'o') { ans += '1'; p += 2; }
        else if (s[p] == 't') {
            if (s[p+1] == 'w') { ans += '2'; p += 2; }
            else if (s[p+1] == 'h') { ans += '3'; p += 4; }
        }
        else if (s[p] == 'f') {
            if (s[p+1] == 'o') { ans += '4'; p += 3; }
            else if (s[p+1] == 'i') { ans += '5'; p += 3; }
        }
        else if (s[p] == 's') {
            if (s[p+1] == 'i') { ans += '6'; p += 2; }
            else if (s[p+1] == 'e') { ans += '7'; p += 4; }
        }
        else if (s[p] == 'e') { ans += '8'; p += 4; }
        else if (s[p] == 'n') { ans += '9'; p += 3; }
    }
    return stoi(ans);
}