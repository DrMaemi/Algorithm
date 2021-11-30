#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    int ans = 0;

    cin >> word;

    for (char x: word) {
        int n = 0;
        if ('S' <= x) {
            n++;
        }

        if ('Z' <= x) {
            n++;
        }
        
        ans += ((int)x-'A'-n)/3+3;
    }

    cout << ans;
    return 0;
}