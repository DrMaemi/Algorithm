#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;

    cin >> T;
    while (T--) {
        string s;
        stack<char> buf;
        bool valid = 1;

        cin >> s;
        for (char x: s) {
            if (x == ')') {
                if (buf.empty() || buf.top() != '(') {
                    valid = 0;
                    break;
                }

                else buf.pop();
            }

            else buf.push(x);
        }

        buf.empty() && valid? cout << "YES\n": cout << "NO\n";
    }

    return 0;
}