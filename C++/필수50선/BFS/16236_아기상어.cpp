#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct L { int y, x; };
struct P { L l; int d; };

int N, sz = 2, cnt = 2;
int m[20][20];
bool visited[20][20];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
L cur;
vector<P> eats;

bool cmp(P& _1, P& _2) {
    if (_1.d != _2.d) return _1.d < _2.d;
    if (_1.l.y != _2.l.y) return _1.l.y < _2.l.y;
    return _1.l.x < _2.l.x;
}

void bfs() {
    eats.clear();
    fill(&visited[0][0], &visited[N-1][N], 0);
    queue<L> q;
    q.push(cur);
    int d = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            L l = q.front(); q.pop();
            if (m[l.y][l.x] && m[l.y][l.x] < sz)
                eats.push_back({l, d});
            for (int i=0; i<4; i++) {
                int ny = l.y+dy[i], nx = l.x+dx[i];
                if (ny < 0 || N <= ny || nx < 0 || N <= nx || visited[ny][nx])
                    continue;
                if (m[ny][nx] <= sz) {
                    q.push({ny, nx});
                    visited[ny][nx] = 1;
                }
            }
        }
        d++;
    }
}

int move() {
    if (eats.empty())
        return 0;
    if (eats.size() > 1)
        sort(eats.begin(), eats.end(), cmp);
    cur = eats.front().l;
    m[cur.y][cur.x] = 0;
    if (!--cnt) {
        sz++;
        cnt = sz;
    }
    return eats.front().d;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int y=0; y<N; y++)
        for (int x=0; x<N; x++) {
            cin >> m[y][x];
            if (m[y][x] == 9) {
                cur = {y, x};
                m[y][x] = 0;
            }
        }
    int ans = 0;
    while (1) {
        bfs();
        int d = move();
        if (!d) break;
        ans += d;
    }
    cout << ans;
    return 0;
}

/*
-요구사항-
몇 초 동안 아기상어가 돌아다니나?

-로직-
맵 입력받고, 아기상어 위치 입력 받고.
큐를 이용해서 모든 공간을 검사하나? 자기 크기에 따라 루트가 제한됨.
현재 크기와 위치로부터 먹잇감이 있는 위치들을 거리에 따라 큐에 넣어야할 듯.
최소거리를 가지는 먹잇감 위치로 바로 이동.
해당 조건의 먹잇감이 다수라면 북, 동쪽 방향 끝의 먹이 우선순위로 이동.
현 상황에서 다시 공간 검사.
*/