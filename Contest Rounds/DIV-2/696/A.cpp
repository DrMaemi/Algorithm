#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a, b;
        string s; cin >> s;
        for (char c: s) b.push_back(c-'0');
        a.push_back(1);
        for (int i=1; i<n; i++)
            if (1+b[i] != a[i-1]+b[i-1]) a.push_back(1);
            else a.push_back(0);
        for (int x: a) cout << x;
        cout << "\n";
    }
    return 0;
}