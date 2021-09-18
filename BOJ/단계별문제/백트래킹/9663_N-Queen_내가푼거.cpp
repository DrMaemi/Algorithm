#include <iostream>
using namespace std;

int N, answer = 0;
bool* horizontal;
bool* diagonal;
bool* antidiagonal;

bool valid(int c, int r) {
    if (horizontal[r] || diagonal[N-1-r+c] || antidiagonal[r+c])
        return false;
    return true;
}

void solve(int c) {
    if (c == N) {
        answer++;
        return;
    }
    for (int r=0; r<N; r++) {
        if (!valid(c, r)) {
            continue;
        }
        horizontal[r] = diagonal[N-1-r+c] = antidiagonal[r+c] = true;
        solve(c+1);
        horizontal[r] = diagonal[N-1-r+c] = antidiagonal[r+c] = false;
    }
}

void malloc_1d_arrs(int size) {
    horizontal = (bool*)malloc(sizeof(bool)*size);
    fill(horizontal, horizontal+size, false);
    diagonal = (bool*)malloc(sizeof(bool)*(2*size-1));
    fill(diagonal, diagonal+(2*size-1), false);
    antidiagonal = (bool*)malloc(sizeof(bool)*(2*size-1));
    fill(antidiagonal, antidiagonal+(2*size-1), false);
}

int main(void) {
    cin >> N;
    malloc_1d_arrs(N);
    solve(0);
    cout << answer;
    return 0;
}