#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

typedef struct loc {
    int r;
    int c;
} l;

typedef struct pair {
    l R;
    l B;
} p;

int N, M;
char map[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];
queue<p> q;

p pop_front() {
    p front = q.front();
    q.pop();
    return front;
}

p left(l R, l B) {
    int nc = R.c;
    while (map[R.r][nc-1] != '#' && map[R.r][nc] != 'O') {
        nc--;
    }
    l new_R = {R.r, nc};
    nc = B.c;
    while (map[B.r][nc-1] != '#' && map[B.r][nc] != 'O') {
        nc--;
    }
    l new_B = {B.r, nc};
    return {new_R, new_B};
}

p right(l R, l B) {
    int nc = R.c;
    while (map[R.r][nc+1] != '#' && map[R.r][nc] != 'O') {
        nc++;
    }
    l new_R = {R.r, nc};
    nc = B.c;
    while (map[B.r][nc+1] != '#' && map[B.r][nc] != 'O') {
        nc++;
    }
    l new_B = {B.r, nc};
    return {new_R, new_B};
}

p up (l R, l B) {
    int nr = R.r;
    while (map[nr-1][R.c] != '#' && map[nr][R.c] != 'O') {
        nr--;
    }
    l new_R = {nr, R.c};
    nr = B.r;
    while (map[nr-1][B.c] != '#' && map[nr][B.c] != 'O') {
        nr--;
    }
    l new_B = {nr, B.c};
    return {new_R, new_B};
}

p down (l R, l B) {
    int nr = R.r;
    while (map[nr+1][R.c] != '#' && map[nr][R.c] != 'O') {
        nr++;
    }
    l new_R = {nr, R.c};
    nr = B.r;
    while (map[nr+1][B.c] != '#' && map[nr][B.c] != 'O') {
        nr++;
    }
    l new_B = {nr, B.c};
    return {new_R, new_B};
}

int solve() {
    int answer = 0; p next; bool done = false;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            p current = pop_front();
            if (map[current.R.r][current.R.c] == 'O') {
                done = true;
                break;
            }
            next = left(current.R, current.B);
            if (map[next.B.r][next.B.c] != 'O') {
                if (next.R.r == next.B.r && next.R.c == next.B.c) {
                    if (current.R.c < current.B.c)
                        next.B.c++;
                    else
                        next.R.c++;
                }
                if (!visited[next.R.r][next.R.c][next.B.r][next.B.c]) {
                    q.push(next);
                    visited[next.R.r][next.R.c][next.B.r][next.B.c] = true;
                }  
            }
            next = right(current.R, current.B);
            if (map[next.B.r][next.B.c] != 'O') {
                if (next.R.r == next.B.r && next.R.c == next.B.c) {
                    if (current.R.c < current.B.c)
                        next.R.c--;
                    else
                        next.B.c--;
                }
                if (!visited[next.R.r][next.R.c][next.B.r][next.B.c]) {
                    q.push(next);
                    visited[next.R.r][next.R.c][next.B.r][next.B.c] = true;
                }
            }
            next = up(current.R, current.B);
            if (map[next.B.r][next.B.c] != 'O') {
                if (next.R.r == next.B.r && next.R.c == next.B.c) {
                    if (current.R.r < current.B.r)
                        next.B.r++;
                    else
                        next.R.r++;
                }
                if (!visited[next.R.r][next.R.c][next.B.r][next.B.c]) {
                    q.push(next);
                    visited[next.R.r][next.R.c][next.B.r][next.B.c] = true;
                }
            }
            next = down(current.R, current.B);
            if (map[next.B.r][next.B.c] != 'O') {
                if (next.R.r == next.B.r && next.R.c == next.B.c) {
                    if (current.R.r < current.B.r)
                        next.R.r--;
                    else
                        next.B.r--;
                }
                if (!visited[next.R.r][next.R.c][next.B.r][next.B.c]) {
                    q.push(next);
                    visited[next.R.r][next.R.c][next.B.r][next.B.c] = true;
                }
            }
        }
        if (done) break;
        if (answer == 10) return -1;
        answer++;
    }
    if (done) return answer;
    return -1;
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    loc R, B;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R')
                R = {i, j};
            else if (map[i][j] == 'B')
                B = {i, j};
        }
    }
    q.push({R, B});
    visited[R.r][R.c][B.r][B.c] = true;
    cout << solve();
    return 0;
}