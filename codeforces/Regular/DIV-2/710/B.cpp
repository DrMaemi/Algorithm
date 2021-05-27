#include <iostream>
using namespace std;
#define S string

int N, K, ans;
S s;

void dfs(int cur, int sum) {
    int end = cur+K;
    if (N <= end) {
        ans = sum;
        return;
    }
    bool f = 0;
    for (int i=end; i>cur; i--)
        if (s[i] == 'x') {
            dfs(i, sum); f= 1;
            break;
        }
        else if (s[i] == '*') {
            s[i] = 'x';
            dfs(i, sum+1); f= 1;
            break;
        }
    if (!f) ans = sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> N >> K >> s;
        int cur, sum = 0; ans = 50;
        for (int i=0; i<N; i++)
            if (s[i] == '*') {
                s[i] = 'x'; cur = i;
                sum++; break;
            }
        for (int i=N-1; i>=0; i--)
            if (s[i] == '*') {
                s[i] = 'x'; sum++;
                break;
            }
        dfs(cur, sum);
        cout << ans << "\n";
    }
    return 0;
}