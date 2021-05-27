#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define V vector
struct L { int r, c; };

int R, C;
V<V<int>> map;
queue<L> swan;
V<V<bool>> visited;
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
V<L> VL;

void print_map() {
    cout << "print_map():\n";
    for (int r=0; r<R; r++) {
        for (int c=0; c<C; c++)
            cout << map[r][c];
        cout << "\n";
    }
}

bool meet() {
    queue<L> swan_m;
    while (!swan.empty()) {
        L l = swan.front(); swan.pop();
        if (l.r == VL[1].r && l.c == VL[1].c)
            return 1;
        for (int i=0; i<4; i++) {
            int nr = l.r+dr[i], nc = l.c+dc[i];
            if (nr < 0 || R <= nr || nc < 0 || C <= nc || visited[nr][nc])
                continue;
            if (map[nr][nc])
                swan_m.push({nr, nc});
            else
                swan.push({nr, nc});
            visited[nr][nc] = 1;
        }
    }
    swap(swan, swan_m);
    return 0;
}

int main() {
    /* cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0); */
    cin >> R >> C;
    queue<L> q, m;
    map.resize(R); visited.resize(R);
    for (int r=0; r<R; r++) {
        map[r].resize(C, 0);
        visited[r].resize(C, 0);
        string in; cin >> in;
        for (int c=0; c<C; c++) {
            if (in[c] == 'X')
                map[r][c] = 1;
            else {
                q.push({r, c});
                if (in[c] == 'L')
                    VL.push_back({r, c});
            }
        }
    }
    swan.push(VL[0]);
    int days = 0;
    while (!meet()) {
        while (!q.empty()) {
            L l = q.front(); q.pop();
            for (int i=0; i<4; i++) {
                int nr = l.r+dr[i], nc = l.c+dc[i];
                if (nr < 0 || R <= nr || nc < 0 || C <= nc)
                    continue;
                if (map[nr][nc]) {
                    map[nr][nc] = 0;
                    m.push({nr, nc});
                }
            }
        }
        q = m;
        queue<L> emp; swap(m, emp);
        days++;
        cout << days << " days, ";
        print_map();
    }
    cout << days;
    return 0;
}