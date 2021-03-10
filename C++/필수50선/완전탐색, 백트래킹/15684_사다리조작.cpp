#include <iostream>
#include <vector>
using namespace std;
#define V vector
#define MAX (N-1)*H+1

// 세로선 개수 N, 실제 가로선 개수 M, 점선 위치 개수 H
int N, M, H;
V<V<bool>> adj;
int _min;

bool valid() {
    bool f = 1;
    for (int i=1; i<=N; i++) {
        int a = 1, b = i;
        while (a != H+1) {
            if (adj[a][b-1])
                b -= 1;
            else if (adj[a][b])
                b += 1;
            a++;
        }
        if (b != i) {
            f = 0;
            break;
        }
    }
    return f;
}

void select(int h, int add) {
    if (add > 3)
        return;
    if (valid()) {
        _min = min(_min, add);
        return;
    }
    for (int a=h; a<=H; a++)
        for (int b=1; b<N; b++)
            if (!adj[a][b-1] && !adj[a][b] && !adj[a][b+1]) {
                adj[a][b] = 1;
                select(a, add+1);
                adj[a][b] = 0;
            }
}


int main() {
    cin >> N >> M >> H;
    adj.resize(H+1, V<bool>(N+1));
    _min = MAX;
    while (M--) {
        // b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    select(1, 0);
    cout << (_min == MAX? -1: _min);
    return 0;
}