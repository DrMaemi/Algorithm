#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000

using namespace std;

int r, c, answer;
int world[MAX][MAX];
queue<vector<int>> tomatos;
vector<vector<int>> check;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool is_done();
int bfs();

int main(void) {
    ios::sync_with_stdio(false);
    answer = -1;
    cin >> c >> r;
    for (int y=0; y<r; y++) {
        for (int x=0; x<c; x++) {
            cin >> world[y][x];
            if (world[y][x] == 1) {
                vector<int> pos = {y, x};
                tomatos.push(pos);
            }
            else if (world[y][x] == 0) {
                vector<int> pos = {y, x};
                check.push_back(pos);
            }
        }
    }
    cout << bfs() << "\n";
    return 0;
}

bool is_done() {
    bool result = true;
    for (int i=0; i<check.size(); i++) {
        int y = check[i][0];
        int x = check[i][1];
        if (world[y][x] == 0) {
            result = false;
            break;
        }
    }
    return result;
}

int bfs() {
    while (!tomatos.empty()) {
        answer++;
        int tomatosSize = tomatos.size();
        for (int t=0; t<tomatosSize; t++){
            vector<int> pos = tomatos.front();
            int y = pos[0];
            int x = pos[1];
            tomatos.pop();
            for (int i=0; i<4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (world[ny][nx] == 0) {
                    world[ny][nx] = 1;
                    vector<int> pos = {ny, nx};
                    tomatos.push(pos);
                }
            }
        }
    }
    if (is_done()) {
        return answer;
    }
    return -1;
}