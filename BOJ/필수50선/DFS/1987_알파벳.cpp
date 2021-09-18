#include <iostream>
#include <vector>
using namespace std;
#define V vector

int R, C;
V<V<int>> M;
bool visited[26];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
int ans = 0;

void dfs(int y, int x, int s) {
    if (visited[M[y][x]]) {
        ans = max(ans, s);
        return;
    }
    visited[M[y][x]] = 1;
    s++;
    for (int i=0; i<4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (0 <= ny && ny < R && 0 <= nx && nx < C)
            dfs(ny, nx, s);
    }
    visited[M[y][x]] = 0;
    s--;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> R >> C;
    M.resize(R, V<int>(C));
    for (int i=0; i<R; i++) {
        string s; cin >> s;
        for (int j=0; j<s.length(); j++)
            M[i][j] = s[j]-'A';
    }
    int s = 0;
    dfs(0, 0, s);
    cout << ans;
    return 0;
}