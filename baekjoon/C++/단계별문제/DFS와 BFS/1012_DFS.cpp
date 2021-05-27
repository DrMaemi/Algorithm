#include <iostream>
#include <vector>
#include <cstring>

#define MAX 50

using namespace std;

int testcase, c, r, n, answer;
vector<int> answers;
int world[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int y, int x);

int main(void) {
    ios::sync_with_stdio(false);
    cin >> testcase;
    for (int tc=0; tc<testcase; tc++) {
        answer = 0;
        memset(world, 0, sizeof(world));
        memset(visited, 0, sizeof(visited));
        cin >> c >> r >> n;
        for (int b=0; b<n; b++) {
            int x, y;
            cin >> x >> y;
            world[y][x] = 1;
        }
        for (int y=0; y<r; y++) {
            for (int x=0; x<c; x++) {
                if (world[y][x] == 1 && !visited[y][x]) {
                    answer++;
                    dfs(y, x);
                }
            }
        }
        answers.push_back(answer);
    }
    for (int i=0; i<answers.size(); i++) {
        cout << answers[i] << "\n";
    }
    return 0;
}

void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
        if (world[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}