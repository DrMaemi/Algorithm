#include <iostream>
using namespace std;
#define MAX 100001

int A[MAX];
bool visited[MAX], done[MAX];
int cnt;

void dfs(int i) {
    if (done[i]) return;
    if (!visited[i]) {
        visited[i] = 1;
        dfs(A[i]);
    }
    else {
        for (int p=A[i]; p!=i; p=A[p])
            cnt++;
        cnt++;
    }
    done[i] = 1;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        fill(visited, visited+N+1, 0);
        fill(done, done+N+1, 0);
        cnt = 0;
        for (int i=1; i<=N; i++)
            cin >> A[i];
        for (int i=1; i<=N; i++)
            dfs(i);
        cout << N-cnt << "\n";
    }
    return 0;
}