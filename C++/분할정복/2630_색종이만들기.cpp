#include <iostream>
#include <cmath>

#define MAX 128

using namespace std;

int world[MAX][MAX];
int N, blue, white;

void solve(int y, int x, int size) {
    int check = world[y][x];
    for (int i=y; i<y+size; i++) {
        for (int j=x; j<x+size; j++) {
            if (check != world[i][j]) {
                check = 2;
                break;
            }
        }
    }
    if (check == 2) {
        int resize = size/2;
        solve(y, x, resize);
        solve(y+resize, x, resize);
        solve(y, x+resize, resize);
        solve(y+resize, x+resize, resize);
    }
    else if (check) {
        blue++;
    }
    else {
        white++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> world[i][j];
        }
    }
    solve(0, 0, N);
    printf("%d\n%d\n", white, blue);
    return 0;
}