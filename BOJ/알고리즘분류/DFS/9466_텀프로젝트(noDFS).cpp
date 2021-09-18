#include <iostream>
using namespace std;

int A[100001];
bool visited[100001], done[100001];

int main() {
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i=1; i<=N; i++)
            cin >> A[i];
        int cnt = 0;
        fill(done, done+N+1, 0);
        fill(visited, visited+N+1, 0);
        for (int i=1; i<=N; i++)
            if (!visited[i]) {
                visited[i] = 1;
                for (int p=A[i]; ; p=A[p]) {
                    if (p < i || done[p])
                        break;
                    if (visited[p]) {
                        done[p] = 1;
                        int _cnt = 1;
                        bool valid = 1;
                        for (int pp=A[p]; pp!=p; pp=A[pp]) {
                            if (done[pp]) {
                                valid = 0; break;
                            }
                            done[pp] = 1; _cnt++;
                        }
                        if (valid) cnt += _cnt;
                        break;
                    }
                    visited[p] = 1;
                }
            }
        cout << N-cnt << "\n";
    }
    return 0;
}