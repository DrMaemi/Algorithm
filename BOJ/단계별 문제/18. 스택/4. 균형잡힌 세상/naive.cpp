#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    while (1) {
        stack<char> stk;
        string ans = "yes";
        getline(cin, s);

        if (s == ".")
            break;

        for (char x: s) {
            if (x == '[' || x == '(')
                stk.push(x);

            else if (x == ']') {
                if (stk.empty() || stk.top() != '[') {
                    ans = "no";
                    break;
                }
                stk.pop();
            }

            else if (x == ')') {
                if (stk.empty() || stk.top() != '(') {
                    ans = "no";
                    break;
                }
                stk.pop();
            }
        }
        
        if (!stk.empty())
            ans = "no";

        cout << ans << "\n";
    }
    
    return 0;
}