#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int cnt = 1;

    getline(cin, S);

    for (char c: S) {
        if (c == ' ') {
            cnt++;
        }
    }

    if (S[0] == ' ') {
        cnt--;
    }

    if (S[S.length()-1] == ' ') {
        cnt--;
    }

    cout << cnt;

    return 0;
}