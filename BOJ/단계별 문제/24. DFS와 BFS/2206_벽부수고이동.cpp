#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef struct location {
    int r, c, w;
} loc;

int N, M;
int map[1001][1001];
bool visited[1001][1001][2];
int dx[] = {0, 0, -1 ,1};
int dy[] = {-1 ,1, 0, 0};
queue<loc> q;

int solve() {
    int answer = 0;
    while (!q.empty()) {
        answer++;
        int size = q.size();
        while (size--) {
            loc l = q.front(); q.pop();
            if (l.r == N && l.c == M) return answer;
            for (int d=0; d<4; d++) {
                int r = l.r+dy[d], c = l.c+dx[d];
                if (r < 1 || N < r || c < 1 || M < c)
                    continue;
                if (map[r][c]) {
                    if (l.w && !visited[r][c][0]) {
                        q.push({r, c, 0});
                        visited[r][c][0] = true;
                    }
                    continue;
                }
                if (!visited[r][c][l.w]) {
                    q.push({r, c, l.w});
                    visited[r][c][l.w] = true;
                }
            }
        }
    }
    return -1;
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    string buf;
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> buf;
        for (int j=0; j<M; j++)
            map[i][j+1] = buf[j]-'0';
    }
    q.push({1, 1, 1});
    cout << solve();
    return 0;
}