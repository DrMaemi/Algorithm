#include <iostream>

#define MAX 8

using namespace std;

int N, M;
int answers[MAX];
int cursor = 1;

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
    for (int i=cursor; i<=N; i++) {
        answers[depth] = i;
        cursor = i+1;
        dfs(depth+1);
    }
}

int main(void) {
    cin >> N >> M;
    dfs(0);
    return 0;
}