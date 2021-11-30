#include <iostream>
#include <set>
using namespace std;

int main() {
    int T, ans;

    cin >> T;
    ans = T;

    while (T--) {
        string word;
        set<char> appeared;

        cin >> word;

        for (int i=0; i<word.length(); i++) {
            if (appeared.find(word[i]) == appeared.end())
                appeared.insert(word[i]);

            else if (word[i-1] != word[i]) {
                ans--;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}