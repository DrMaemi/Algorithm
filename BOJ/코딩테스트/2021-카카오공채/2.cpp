#include <string>
#include <vector>
#include <queue>
#define V vector
#define S string
using namespace std;
struct L { int y, x; };

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

V<int> solution(V<V<S>> places) {
    V<int> ans;
    for (V<S> place: places) {
        bool valid = 1;
        for (int y=0; y<place.size(); y++) {
            for (int x=0; x<place[y].size(); x++) {
                if (place[y][x] == 'P') {
                    queue<L> q; bool visited[5][5] = {0,};
                    q.push({y, x}); visited[y][x] = 1;
                    bool start = 1; int d = 0;
                    while (!q.empty()) {
                        int size = q.size();
                        while (size--) {
                            L l = q.front(); q.pop();
                            if (place[l.y][l.x] == 'P') {
                                if (start) start = 0;
                                else { valid = 0; break; }
                            }
                            for (int i=0; i<4; i++) {
                                int ny = l.y+dy[i], nx = l.x+dx[i];
                                if (ny < 0 || nx < 0 || 4 < ny || 4 < nx ) continue;
                                if (visited[ny][nx] || place[ny][nx] == 'X') continue;
                                else { q.push({ny, nx}); visited[ny][nx] = 1; }
                            }
                        }
                        d++;
                        if (!valid || d == 3) break;
                    }
                }
                if (!valid) break;
            }
            if (!valid) break;
        }
        ans.push_back(valid);
    }
    return ans;
}