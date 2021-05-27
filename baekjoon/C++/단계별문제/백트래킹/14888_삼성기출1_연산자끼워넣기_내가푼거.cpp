#include <iostream>
#include <climits>
using namespace std;

int N;
int* operands;
int* cases;
int operators[4];
int _max = INT_MIN, _min = INT_MAX;

void solve(int depth, int result) {
    if (depth == N) {
        if (result > _max) _max = result;
        if (result < _min) _min = result;
        return;
    }
    for (int i=0; i<4; i++) {
        if (operators[i]) {
            operators[i]--;
            if (i == 0) solve(depth+1, result+operands[depth]);
            else if (i == 1) solve(depth+1, result-operands[depth]);
            else if (i == 2) solve(depth+1, result*operands[depth]);
            else solve(depth+1, result/operands[depth]);
            operators[i]++;
        }
    }
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    operands = (int*)malloc(sizeof(int)*N);
    cases = (int*)malloc(sizeof(int)*(N-1));
    for (int i=0; i<N; i++) {
        cin >> operands[i];
    }
    for (int i=0; i<4; i++) {
        cin >> operators[i];
    }
    solve(1, operands[0]);
    cout << _max << "\n";
    cout << _min;
    return 0;
}