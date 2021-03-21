#include <iostream>
#include <queue>
using namespace std;
struct P { int t; char dir; };
struct Loc { int y, x; };

int N, K, L;
int m[101][101];
int snake[101][101];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    while (K--) {
        int y, x;
        cin >> y >> x;
        m[y][x] = 1;
    }
    fill(&snake[1][1], &snake[N][N+1], -1);
    cin >> L;
    queue<P> q;
    while (L--) {
        int t; char dir;
        cin >> t >> dir;
        q.push({t, dir});
    }
    snake[1][1] = 0;
    Loc head = {1, 1}, tail = {1, 1};
    int dir = 0, time = 0;
    while (1) {
        time++;
        int ny = head.y+dy[dir], nx = head.x+dx[dir];
        if (ny <= 0 || N < ny || nx <= 0 || N < nx || snake[ny][nx] != -1)
            break;
        head = {ny, nx};
        if (m[ny][nx])
            m[ny][nx] = 0;
        else {
            int& tdir = snake[tail.y][tail.x];
            tail = {tail.y+dy[tdir], tail.x+dx[tdir]};
            tdir = -1;
        }
        P p = q.front();
        if (p.t == time) {
            if (p.dir == 'L')
                dir = (3+dir)%4;
            else if (p.dir == 'D')
                dir = (1+dir)%4;
            q.pop();
        }
        snake[ny][nx] = dir;
    }
    cout << time;
    return 0;
}