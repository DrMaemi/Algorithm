#include <iostream>
#include <algorithm>
using namespace std;

int N;
int* memo;
bool* visited;

int find_min(int a, int b, int c) {
    if (a <= b) {
        if (a <= c) return a;
        return c;
    }
    if (b <= c) return b;
    return c;
}

int solve(int target) {
    if (visited[target]) {
        return memo[target];
    }
    int mod_2 = target%2;
    int mod_3 = target%3;
    memo[target] = find_min(solve(target-1)+1,
                            solve(target/2)+mod_2+1,
                            solve(target/3)+mod_3+1);
    visited[target] = true;
    return memo[target];
}

void initialize() {
    cin >> N;
    memo = (int*)malloc(sizeof(int)*(N+1));
    visited = (bool*)malloc(sizeof(bool)*(N+1));
    fill(visited, visited+(N+1), false);
    memo[1] = 0; visited[1] = true;
    memo[2] = 1; visited[2] = true;
    memo[3] = 1; visited[3] = true;
}

int main(void) {
    initialize();
    cout << solve(N);
    return 0;
}