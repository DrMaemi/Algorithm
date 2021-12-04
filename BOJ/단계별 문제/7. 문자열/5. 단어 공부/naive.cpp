// DrMaemi - 4916KB, 40ms
#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int cnts['z'-'a'+1] = { 0 };
    int max_cnt = 0, index = 0;
    bool dup = false;
    char ans;

    cin >> S;
    for (char c: S) {
        int i = tolower(c)-'a';
        cnts[i]++;
    }

    for (int i=0; i<'z'-'a'+1; i++) {
        if (max_cnt < cnts[i]) {
            max_cnt = cnts[i];
            index = i;
        }
    }

    ans = (int)'A'+index;

    for (int cnt: cnts) {
        if (max_cnt == cnt) {
            if (dup) {
                ans = '?';
                break;
            }
            
            dup = true;
        }
    }

    cout << ans;

    return 0;
}