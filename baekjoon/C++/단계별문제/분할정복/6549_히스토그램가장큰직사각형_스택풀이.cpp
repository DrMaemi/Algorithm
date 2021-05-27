#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define V vector
typedef long long ll;
struct P { int l, h; };

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    while (1) {
        cin >> n;
        if (!n) break;
        stack<P> s;
        ll ans = 0;
        for (int i=0; i<=n; i++) {
            int h;
            if (i < n) cin >> h;
            else h = -1;
            int l = i;
            while (!s.empty() && h < s.top().h) {
                ans = max(ans, ((ll)i-s.top().l)*s.top().h);
                l = s.top().l;
                s.pop();
            }
            s.push({l, h});
        }
        cout << ans << "\n";
    }
    return 0;
}