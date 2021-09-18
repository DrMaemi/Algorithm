#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

struct loc {
    int z;
    int y;
    int x;
};

int x, y, z;
int box[MAX][MAX][MAX];
queue<loc> q;

int dz[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {-1, 1, 0, 0, 0, 0};

bool need_to_solve(int x, int y, int z) {
    bool result = false;
    for (int i=0; i<z; i++) {
        for (int j=0; j<y; j++) {
            for (int k=0; k<x; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) 
                    q.push({i, j, k});
                else if (!box[i][j][k])
                    result = true;
            }
        }
    }
    return result;
}

loc pop_front() {
    loc location = q.front();
    q.pop();
    return location;
}

bool check_box() {
    for (int i=0; i<z; i++)
        for (int j=0; j<y; j++)
            for (int k=0; k<x; k++)
                if (!box[i][j][k]) return false;
    return true;
}

bool is_valid_loc(loc l) {
    if ((l.z < 0 || z <= l.z) || (l.y < 0 || y <= l.y) || (l.x < 0 || x <= l.x)
        || box[l.z][l.y][l.x]) return false;
    return true;
}

int solve() {
    cin >> x >> y >> z;
    if (!need_to_solve(x, y, z)) {
        return 0;
    }
    int answer = -1;
    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            loc l = pop_front();
            for (int cs=0; cs<6; cs++) {
                loc nx = {l.z+dz[cs], l.y+dy[cs], l.x+dx[cs]};
                if (is_valid_loc(nx)) {
                    box[nx.z][nx.y][nx.x] = 1;
                    q.push(nx);
                }
            }
        }
        answer++;
    }
    if (check_box()) return answer;
    return -1;
} 

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cout << solve();
    return 0;
}