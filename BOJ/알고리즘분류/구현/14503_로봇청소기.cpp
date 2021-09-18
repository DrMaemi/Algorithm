#include <iostream>
#include <vector>
using namespace std;
#define V vector
struct L { int r, c, d; };

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};
int N, M;
V<V<int>> m;
V<V<bool>> visited;

bool is_wall(int r, int c) {
    if (r < 0 || N <= r || c < 0 || M <= c || m[r][c])
        return 1;
    return 0;
}

bool valid(int r, int c) {
    if (0 <= r && r < N && 0 <= c && c < M && !m[r][c] && !visited[r][c])
        return 1;
    return 0;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    L l;
    cin >> l.r >> l.c >> l.d;
    m.resize(N, V<int>(M));
    visited.resize(N, V<bool>(M));
    for (int r=0; r<N; r++)
        for (int c=0; c<M; c++)
            cin >> m[r][c];
    int cnt = 0, ans = 1, nr, nc;
    visited[l.r][l.c] = 1;
    while (1) {
        nr = l.r+dr[l.d], nc = l.c+dc[l.d];
        if (valid(nr, nc)) {
            visited[nr][nc] = 1;
            l = {nr, nc, (3+l.d)%4};
            cnt = 0;
            ans++;
        }
        else {
            l.d = (3+l.d)%4;
            cnt++;
        }
        if (cnt == 4) {
            nr = l.r+dr[(3+l.d)%4], nc = l.c+dc[(3+l.d)%4];
            if (is_wall(nr, nc)) break;
            l = {nr, nc, l.d};
            cnt = 0;
        }
    }
    cout << ans;
    return 0;
}