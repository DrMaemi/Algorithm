#include <iostream>
using namespace std;

int N, M;
int A[8];

void f(int depth) {
    if (depth == M) {
        for (int i=0; i<depth; i++)
            cout << A[i] << " ";
        cout << "\n";

        return;
    }

    for (int i=1; i<=N; i++) {
        A[depth] = i;
        f(depth+1);
    }
}

int main() {
    cin >> N >> M;

    f(0);

    return 0;
}