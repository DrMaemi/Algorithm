#include <iostream>

#define MAX 8

using namespace std;

int N, M, answers[MAX];
bool visited[MAX];

void print_answer() {
    for (int i=0; i<M; i++) {
        cout << answers[i] << " ";
    }
    cout << "\n";
}

void dfs(int depth) {
    if (depth == M) {
        print_answer();
        return;
    }
    for (int i=0; i<N; i++) {
        if (visited[i]) continue;
        answers[depth] = i+1;
        visited[i] = true;
        dfs(depth+1);
        visited[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    dfs(0);
    return 0;
}