#include <iostream>
#include <vector>
using namespace std;
#define V vector
#define MAX 1000000

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    V<V<int>> H(N, V<int>(3));
    V<V<int>> CM(N, V<int>(3));
    for (int i=0; i<N; i++)
        cin >> H[i][0] >> H[i][1] >> H[i][2];
    int _min = MAX;
    for (int i=0; i<3; i++) {
        fill(CM[0].begin(), CM[0].end(), MAX);
        CM[0][i] = H[0][i];
        for (int j=1; j<N; j++)
            for (int k=0; k<3; k++)
                CM[j][k] = min(CM[j-1][(k+1)%3], CM[j-1][(k+2)%3])+H[j][k];
        _min = min(_min, min(CM[N-1][(i+1)%3], CM[N-1][(i+2)%3]));
    }
    cout << _min;
    return 0;
}