#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    stack<int> s;

    cin >> N;
    while (N--) {
        string command;

        cin >> command;
        if (command == "push") {
            int n;

            cin >> n;
            s.push(n);
        }
        else if (command == "top") {
            if (s.empty()) cout << -1 << "\n";
            else cout << s.top() << "\n";
        }
        else if (command == "pop") {
            if (s.empty())
                cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (command == "size")
            cout << s.size() << "\n";
        else
            cout << s.empty() << "\n";
    }

    return 0;
}