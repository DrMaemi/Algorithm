#include <iostream>
using namespace std;

int N, M;
int* answer;

void print_answer(int size) {
    for (int i=0; i<size; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

void dfs(int depth) {
    if (depth == M) {
        print_answer(M);
        return;
    }
    for (int i=1; i<=N; i++) {
        answer[depth] = i;
        dfs(depth+1);
    }
}

int* malloc_1d_arr(int size) {
    int* _1d_arr = (int*)malloc(sizeof(int)*size);
    return _1d_arr;
}

int main(void) {
    cin >> N >> M;
    answer = malloc_1d_arr(M);
    dfs(0);
    return 0;
}