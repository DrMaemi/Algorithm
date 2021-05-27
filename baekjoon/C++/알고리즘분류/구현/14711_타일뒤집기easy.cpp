#include <iostream>
using namespace std;

int N;
string m[1001];
bool visited[1001][1001];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> m[0];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            if (m[i][j] == '#') {
                if (j) visited[i][j-1] ^= 1;
                if (j < N-1) visited[i][j+1] ^= 1;
                if (i < N-1) visited[i+1][j] ^= 1;
            }
        for (int j=0; j<N; j++)
            m[i+1] += visited[i][j]? '#': '.';
        cout  << m[i] << "\n";
    }
    return 0;
}