#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define V vector
typedef long long ll;

void print_1d(V<int>& v) {
    cout << "print_1d():\n";
    for (int x: v)
        cout << x << " ";
    cout << "\n";
}

int main() {
    int n;
    while (1) {
        cin >> n;
        if (!n) break;
        V<int> H(n), L(n, n);
        for (int i=0; i<n; i++)
            cin >> H[i];
        stack<int> s;
        for (int i=0; i<n; i++) {
            while (!s.empty() && H[i] < H[s.top()]) {
                L[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        print_1d(L);
        ll _max = 0;
        for (int i=0; i<n; i++)
            _max = max(_max, (ll)H[i]*(L[i]-i));
        cout << _max << "\n";
    }
    return 0;
}