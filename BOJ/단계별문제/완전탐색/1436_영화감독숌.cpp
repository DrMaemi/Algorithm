#include <iostream>
#include <climits>
#include <string>
using namespace std;

int main() {
    int N; cin >> N;
    int n = 0, r = 0;
    for (int i=666; i!=INT_MAX; i++) {
        string s = to_string(i);
        int _6 = 0;
        for (int j=0; j<s.length(); j++) {
            if (s[j] == '6') _6++;
            else _6 = 0;
            if (_6 == 3) {
                n++; break;
            }
        }
        if (n == N) {
            r = i; break;
        }
    }
    cout << r;
    return 0;
}