#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 25
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))

using namespace std;

int N;
int world[MAX][MAX];
bool visited[MAX][MAX];
int house_cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> answer;

void dfs(int x, int y);

int main(void) {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        for (int j=0; j<N; j++) {
            world[i][j] = temp[j] - '0';
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (world[i][j] == 1 && !visited[i][j]) {
                house_cnt = 0;
                dfs(i, j);
                answer.push_back(house_cnt);
            }
        }
    }
    sortvec(answer);
    cout << answer.size() << "\n";
    for (auto it=answer.begin(); it!=answer.end(); it++) {
        cout << *it << "\n";
    }
    return 0;
}

void dfs(int x, int y) {
    house_cnt++;
    visited[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (world[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}