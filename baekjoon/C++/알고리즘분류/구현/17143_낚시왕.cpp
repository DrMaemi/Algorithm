#include <iostream>
using namespace std;
struct Shark { int s, d, z; };
struct L { int r, c, d; };

int R, C, M;
Shark m[101][101];
bool visited[101][101];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

// r, c에 있는 상어를 d방향으로 s칸 만큼 움직인다.
L move(int r, int c, int d, int s) {
    printf("move - r:%d, c:%d, d:%d, s:%d\n", r, c, d, s);
    int nr = r+dr[d]*s, nc = c+dc[d]*s;
    int nd = (d%2)? d-1: d+1;
    if (r == nr) { // 좌 우
        if (nc <= 0) return move(r, 1, nd, s-c+1);
        else if (C < nc) return move(r, C, nd, s-C+c);
        else return {nr, nc, d};
    }
    else { // 상 하
        if (nr <= 0) return move(1, c, nd, s-r+1);
        else if (R < nr) return move(R, c, nd, s-R+r);
        else return {nr, nc, d};
    }
}

void func(int r, int c, Shark S, bool recur) {
    if ((S.z && !visited[r][c]) || recur) {
        if (!recur) m[r][c].z = 0;
        L dt = move(r, c, S.d, S.s);
        printf("moved - r:%d, c:%d, d:%d\n", dt.r, dt.c, dt.d);
        S.d = dt.d;
        if (visited[dt.r][dt.c]) {
            if (m[dt.r][dt.c].z < S.z)
                m[dt.r][dt.c] = S;
        }
        else {
            visited[dt.r][dt.c] = 1;
            Shark nS = m[dt.r][dt.c];
            m[dt.r][dt.c] = S;
            if (nS.z) {
                printf("exists not moved, s:%d, d:%d, z:%d\n", nS.s, nS.d, nS.z);
                func(dt.r, dt.c, nS, 1);
            }
        }
    }
}

void print_m(int t) {
    printf("after %d:\n", t);
    for (int r=1; r<=R; r++) {
        for (int c=1; c<=C; c++) {
            Shark S = m[r][c];
            if (S.z) {
                printf("r:%d, c:%d, s:%d, d:%d, z:%d\n", r, c, S.s, S.d, S.z);
            }
        }
    }
}

int main() {
    cin >> R >> C >> M;
    while (M--) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        m[r][c] = {s, d-1, z};
    }
    int ans = 0;
    for (int t=1; t<=C; t++) {
        for (int r=1; r<=R; r++)
            if (m[r][t].z) {
                printf("GET - r:%d, c:%d, z:%d\n", r, t, m[r][t].z);
                ans += m[r][t].z;
                m[r][t].z = 0;
                break;
            }
        fill(&visited[0][0], &visited[R][C+1], 0);
        for (int r=1; r<=R; r++) {
            for (int c=1; c<=C; c++) {
                // printf("r:%d, c:%d\n", r, c);
                func(r, c, m[r][c], 0);
            }
        }
        print_m(t);
    }
    cout << ans;
    return 0;
}

/*
-명세-
방향 : 0 - 위 1 - 아래 2 - 오른 3 - 왼
빨간색 숫자가 속력의 크기(칸/초)
이동 시 격자판의 경계를 넘으면 방향을 바꿔 이동.
모든 이동이 끝난 후 한 칸에 여러 상어가 존재하면,
크기가 가장 큰 상어만이 살아남는다.

-설계-
시간 t = 1 ~ C까지 흐를 때, 먼저 상어가 이동해야 함.
RxC 를 순회하며 방문하지 않은 자리에 상어가 있다면 이동 함수 호출.
이동을 끝낸 뒤의 위치가 방문한 자리라면 크기가 큰 상어를 남겨둠.
방문한 자리가 아니라면 그 자리를 방문처리하고, 그 자리에 상어가 있었다면
그 상어에 대해 이동함수 호출(재귀).

이후 해당 열(시간 t)에서 육지(r=0, c=t)와 가장 가까운 곳의 상어를 낚는다.
상어가 없으면 0.

이동 함수:
주어진 방향에 대해 재귀적으로 이동시키는 건 어떨까.
*/