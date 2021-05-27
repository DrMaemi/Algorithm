#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V vector
struct L { int y, x; };

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    V<V<int>> map(N, V<int>(N));
    V<V<int>> v_land(N, V<int>(N));
    V<V<bool>> v_sea(N, V<bool>(N));
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> map[i][j];
    int dy[] = {0, 0, -1, 1};
    int dx[] = {-1, 1, 0, 0};
    int num = 0, ans = 200;
    queue<L> land, sea;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            if (map[y][x] && !v_land[y][x]) {
                v_land[y][x] = ++num;
                land.push({y, x});
                while (!land.empty()) {
                    L l = land.front(); land.pop();
                    for (int k=0; k<4; k++) {
                        int ny = l.y+dy[k], nx = l.x+dx[k];
                        if (ny < 0 || N <= ny || nx < 0 || N <= nx)
                            continue;
                        if (map[ny][nx]) {
                            if (!v_land[ny][nx]) {
                                v_land[ny][nx] = num;
                                land.push({ny, nx});
                            }
                        }
                        else if (!v_sea[ny][nx]) {
                            v_sea[ny][nx] = 1;
                            sea.push({ny, nx});
                        }
                    }
                }
                bool f = 0;
                int len = 1;
                while (!sea.empty()) {
                    int size = sea.size();
                    while (size--) {
                        L l = sea.front(); sea.pop();
                        for (int k=0; k<4; k++) {
                            int ny = l.y+dy[k], nx = l.x+dx[k];
                            if (ny < 0 || N <= ny || nx < 0 || N <= nx)
                                continue;
                            if (map[ny][nx]) {
                                if (v_land[ny][nx] != num) {
                                    ans = min(ans, len);
                                    f = 1; break;
                                }
                            }
                            else if (!v_sea[ny][nx]) {
                                v_sea[ny][nx] = 1;
                                sea.push({ny, nx});
                            }
                        }
                        if (f) break;
                    }
                    if (f) {
                        queue<L> emp;
                        swap(sea, emp);
                        fill(v_sea.begin(), v_sea.end(), V<bool>(N));
                    }
                    len++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}