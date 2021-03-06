#include <iostream>
using namespace std;

int N, M, ans = 0;
bool used[9] = {0};
int A[9];

void f(int depth) {
    if (depth == M) {
        for (int i=0; i<depth; i++)
            cout << A[i] << " ";
        cout << "\n";

        return;
    }

    for (int i=1; i<=N; i++) {
        if (!used[i]) {
            A[depth] = i;
            used[i] = 1;
            f(depth+1);
            used[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;

    f(0);
    
    return 0;
}