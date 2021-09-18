#include <iostream>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

string s1, s2;
int CM[20][20][20][20];

int dp(int i, int j, int x, int y) {
    if (i > j) return y-x+1;
    if (x > y) return j-i+1;
    string s3 = s1.substr(i, j-i+1), s4 = s2.substr(x, y-x+1);
    if (s3 == s4) return 0;
    int& ans = CM[i][j][x][y];
    if (ans == -1)
        ans = 1+min({dp(i+1, j, x, y), dp(i, j-1, x, y), dp(i, j, x+1, y), dp(i, j, x, y-1)});
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> s1 >> s2;
        memset(CM, -1, sizeof CM);
        cout << dp(0, s1.size()-1, 0, s2.size()-1) << "\n";
    }
    return 0;
}