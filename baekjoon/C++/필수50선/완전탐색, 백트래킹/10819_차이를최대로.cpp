#include <iostream>
#include <vector>
using namespace std;
#define V vector

int N;
V<int> A;
V<bool> visited;
int _max;

void dfs(V<int>& S) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (S.size() == N) {
        int sum = 0;
        for (int i=0; i<S.size()-1; i++)
            sum += abs(S[i]-S[i+1]);
        _max = max(_max, sum);
        return;
    }
    for (int i=0; i<N; i++)
        if (!visited[i]) {
            S.push_back(A[i]);
            visited[i] = 1;
            dfs(S);
            S.pop_back();
            visited[i] = 0;
        }
}

int main() {
    cin >> N;
    A.resize(N);
    visited.resize(N);
    for (int i=0; i<N; i++)
        cin >> A[i];
    V<int> S; dfs(S);
    cout << _max;
    return 0;
}