#include <iostream>
using namespace std;

int N, M;
int A[9];

void f(int depth, int n) {
    if (depth == M) {
        for (int i=0; i<depth; i++)
            cout << A[i] << " ";
        cout << "\n";

        return;
    }

    for (int i=n; i<=N; i++) {
        A[depth] = i;
        f(depth+1, i);
    }
}

int main() {
    cin >> N >> M;

    f(0, 1);

    return 0;
}