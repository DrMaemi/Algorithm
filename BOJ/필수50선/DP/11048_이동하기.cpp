#include <iostream>
using namespace std;

int map[1001][1001];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++) {
            cin >> map[i][j];
            map[i][j] += max(map[i-1][j], map[i][j-1]);
        }
    cout << map[N][M];
    return 0;
}