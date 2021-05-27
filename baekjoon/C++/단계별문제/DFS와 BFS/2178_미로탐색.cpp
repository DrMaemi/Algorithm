#include <iostream>
#include <vector>
#include <queue>

#define MAX 100

using namespace std;

int world[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c;

int bfs(int y, int x, int cnt);

int main(void) {
    cin >> r >> c;
    for (int y=0; y<r; y++) {
        string tmp;
        cin >> tmp;
        for (int x=0; x<c; x++) {
            world[y][x] = tmp[x]-'0';
        }
    }
    cout << bfs(0, 0, 1) << "\n";
    return 0;
}

int bfs(int y, int x, int cnt) {
    queue<vector<int>> Q;
    vector<int> pos = {y, x, cnt};
    Q.push(pos);
    visited[y][x] = true;
    while (!Q.empty()) {
        vector<int> cur = Q.front();
        int y = cur[0]; int x = cur[1]; int cnt = cur[2];
        if (y == r-1 && x == c-1) return cnt;
        Q.pop();
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if (world[ny][nx] == 1 && !visited[ny][nx]) {
                vector<int> pos = {ny, nx, cnt+1};
                Q.push(pos);
                visited[ny][nx] = true;
            }
        }
    }
    return cnt;
}