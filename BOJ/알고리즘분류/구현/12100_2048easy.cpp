#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N, ans = 0;

void dfs(int d, V<V<int>> _m) {
    if (d == 5) {
        for (int y=0; y<N; y++)
            for (int x=0; x<N; x++)
                ans = max(ans, _m[y][x]);
        return;
    }
    V<V<int>> m = _m;
    V<V<bool>> merged(N, V<bool>(N));
    for (int x=0; x<N; x++)
        for (int y=1; y<N; y++)
            if (m[y][x]) {
                int _y = y;
                while (_y) {
                    _y--;
                    if (!m[_y][x]) {
                        m[_y][x] = m[_y+1][x];
                        m[_y+1][x] = 0;
                        merged[_y][x] = merged[_y+1][x];
                        merged[_y+1][x] = 0;
                    }
                    else  {
                        if (!merged[_y][x] && !merged[_y+1][x] && m[_y][x] == m[_y+1][x]) {
                            m[_y][x] *= 2;
                            m[_y+1][x] = 0;
                            merged[_y][x] = 1;
                        }
                        break;
                    }
                }
            }
    dfs(d+1, m);
    m = _m;
    fill(merged.begin(), merged.end(), V<bool>(N));
    for (int y=0; y<N; y++)
        for (int x=N-2; x>=0; x--)
            if (m[y][x]) {
                int _x = x;
                while (_x < N-1) {
                    _x++;
                    if (!m[y][_x]) {
                        m[y][_x] = m[y][_x-1];
                        m[y][_x-1] = 0;
                        merged[y][_x] = merged[y][_x-1];
                        merged[y][_x-1] = 0;
                    }
                    else  {
                        if (!merged[y][_x] && !merged[y][_x-1] && m[y][_x] == m[y][_x-1]) {
                            m[y][_x] *= 2;
                            m[y][_x-1] = 0;
                            merged[y][_x] = 1;
                        }
                        break;
                    }
                }
            }
    dfs(d+1, m);
    m = _m;
    fill(merged.begin(), merged.end(), V<bool>(N));
    for (int x=0; x<N; x++)
        for (int y=N-2; y>=0; y--)
            if (m[y][x]) {
                int _y = y;
                while (_y < N-1) {
                    _y++;
                    if (!m[_y][x]) {
                        m[_y][x] = m[_y-1][x];
                        m[_y-1][x] = 0;
                        merged[_y][x] = merged[_y-1][x];
                        merged[_y-1][x] = 0;
                    }
                    else  {
                        if (!merged[_y][x] && !merged[_y-1][x] && m[_y][x] == m[_y-1][x]) {
                            m[_y][x] *= 2;
                            m[_y-1][x] = 0;
                            merged[_y][x] = 1;
                        }
                        break;
                    }
                }
            }
    dfs(d+1, m);
    m = _m;
    fill(merged.begin(), merged.end(), V<bool>(N));
    for (int y=0; y<N; y++)
        for (int x=1; x<N; x++)
            if (m[y][x]) {
                int _x = x;
                while (_x) {
                    _x--;
                    if (!m[y][_x]) {
                        m[y][_x] = m[y][_x+1];
                        m[y][_x+1] = 0;
                        merged[y][_x] = merged[y][_x+1];
                        merged[y][_x+1] = 0;
                    }
                    else  {
                        if (!merged[y][_x] && !merged[y][_x+1] && m[y][_x] == m[y][_x+1]) {
                            m[y][_x] *= 2;
                            m[y][_x+1] = 0;
                            merged[y][_x] = 1;
                        }
                        break;
                    }
                }
            }
    dfs(d+1, m);
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    V<V<int>> m(N, V<int>(N));
    V<V<bool>> merged(N, V<bool>(N));
    for (int y=0; y<N; y++)
        for (int x=0; x<N; x++)
            cin >> m[y][x];
    dfs(0, m);
    cout << ans;
    return 0;
}