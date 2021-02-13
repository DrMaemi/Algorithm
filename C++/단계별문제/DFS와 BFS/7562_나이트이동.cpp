#include <iostream>
#include <queue>
using namespace std;
typedef struct location {
    int r, c;
} loc;

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
queue<loc> q;
int visited[300][300];

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int T, I; cin >> T;
    loc s, e;
    while (T--) {
        cin >> I;
        cin >> s.r >> s.c;
        cin >> e.r >> e.c;
        q.push({s.r, s.c});
        int answer = 0; bool f = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                loc l = q.front(); q.pop();
                if (l.r == e.r && l.c == e.c) {
                    f = 1; break;
                }
                for (int i=0; i<8; i++) {
                    int r = l.r+dr[i], c = l.c+dc[i];
                    if (r < 0 || I <= r || c < 0 || I <= c || visited[r][c])
                        continue;
                    q.push({r, c}); visited[r][c] = true;
                }
            }
            if (f) {
                cout << answer << "\n";
                queue<loc> nq; swap(q, nq);
                for (int i=0; i<I; i++)
                    fill(visited[i], visited[i]+I, 0);
                break;
            }
            answer++;
        }
    }
    return 0;
}