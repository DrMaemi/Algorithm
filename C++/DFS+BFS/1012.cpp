#include <iostream>
#include <vector>

#define MAX 50

using namespace std;

int testcase, c, r, n, answer;
int world[MAX][MAX];

void dfs(int what);

int main(void) {
    cin >> testcase;
    for (int tc=0; tc<testcase; tc++) {
        cin >> c >> r >> n;
        for (int b=0; b<n; b++) {
            int x, y;
            cin >> x >> y;
            world[y][x] = 1;
        }
        int what;
        dfs(what);
        cout << answer << "\n";
    }
    return 0;
}