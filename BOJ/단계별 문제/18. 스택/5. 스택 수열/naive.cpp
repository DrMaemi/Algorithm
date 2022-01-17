#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, p = 1;
    stack<int> stk;
    string ans = "";

    cin >> n;

    while (n--) {
        cin >> x;

        if (stk.empty() || stk.top() < x)
            for (; p<=x; p++) {
                stk.push(p);
                ans += "+\n";
            }

        if (stk.top() == x) {
            stk.pop();
            ans += "-\n";
        }

        else if (x < stk.top()) {
            ans = "";
            break;
        }
    }

    cout << (ans.length()? ans: "NO");

    return 0;
}