#include <iostream>
#include <set>
using namespace std;

int main() {
    int T, ans = 0;
    string word;
    
    cin >> T;

    while (T--) {
        char p;
        bool appeared['z'-'a'+1] = {0};
        bool valid = 1;

        cin >> word;
        p = word[0];
        appeared[p-'a'] = 1;

        for (int i=1; i<word.length(); i++) {
            if (!appeared[word[i]-'a'])
                appeared[word[i]-'a'] = 1;

            else if (word[i] != p) {
                valid = 0;
                break;
            }

            p = word[i];
        }

        if (valid)
            ans++;
    }

    cout << ans;
    return 0;
}