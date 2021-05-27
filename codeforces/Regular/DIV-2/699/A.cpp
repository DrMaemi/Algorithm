#include <iostream>
using namespace std;
struct L { int x, y; };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        L cur = {0, 0};
        L dt; cin >> dt.x >> dt.y;
        string s; cin >> s;
        bool f = 0;
        if (cur.x == dt.x && cur.y == dt.y) {
            f = 1;
        }
        else {
            for (int i=0; i<s.length(); i++) {
                if (s[i] == 'U' && cur.y < dt.y) cur.y++;
                else if (s[i] == 'D' && cur.y > dt.y) cur.y--;
                else if (s[i] == 'R' && cur.x < dt.x) cur.x++;
                else if (s[i] == 'L' && cur.x > dt.x) cur.x--;
                if (cur.x == dt.x && cur.y == dt.y) {
                    f = 1; break;
                }
            }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}