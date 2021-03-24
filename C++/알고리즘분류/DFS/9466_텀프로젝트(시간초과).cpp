#include <iostream>
using namespace std;

int A[100001];
bool has[100001], visited[100001];

int main() {
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        fill(has, has+N+1, 0);
        for (int i=1; i<=N; i++)
            cin >> A[i];
        for (int i=1; i<=N; i++) {
            fill(visited, visited+N+1, 0);
            if (!has[i]) {
                visited[i] = 1;
                int p = A[i];
                for (; !visited[p] && !has[p]; p=A[p])
                    visited[p] = 1;
                if (p == i)
                    for (int i=1; i<=N; i++)
                        if (visited[i]) has[i] = 1;
            }
        }
        int ans = 0;
        for (int i=1; i<=N; i++)
            if (!has[i]) ans++;
        cout << ans << "\n";
    }
    return 0;
}