#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    priority_queue<int> max_h;
    priority_queue<int, vector<int>, greater<int>> min_h;
    N--; int n; cin >> n;
    max_h.push(n);
    cout << n << "\n";
    while (N--) {
        int n; cin >> n;
        if (max_h.size() == min_h.size())
            max_h.push(n);
        else
            min_h.push(n);
        int xt = max_h.top(), nt = min_h.top();
        if (nt < xt) {
            max_h.pop(); min_h.pop();
            max_h.push(nt); min_h.push(xt);
        }
        cout << max_h.top() << "\n";
    }
    return 0;
}