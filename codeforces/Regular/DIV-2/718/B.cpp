#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000000
struct P { int v, i; };

bool cmp(P& _1, P& _2) { return _1.v > _2.v; }

int main() {
    int T; cin >> T;
    while (T--) {
        int N, M, b[100][100], ans[100][100]; cin >> N >> M;
        P p[100];
        for (int i=0; i<N; i++) for (int j=0; j<M; j++) cin >> b[i][j];
        for (int j=0; j<M; j++) {
            p[j].v = ans[0][j] = b[0][j];
            p[j].i = j;
        }
        sort(p, p+M, cmp);
        for (int i=1; i<N; i++) {
            sort(b[i], b[i]+M);
            for (int j=0; j<M; j++) {
                ans[i][p[j].i] = b[i][j];
                p[j].v = min(p[j].v, b[i][j]);
            }
            sort(p, p+M, cmp);
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}