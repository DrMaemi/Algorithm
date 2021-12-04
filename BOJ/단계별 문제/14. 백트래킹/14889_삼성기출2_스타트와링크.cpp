#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int N, _min = INT_MAX;
int S[21][21];
vector<int> start;
vector<int> link;

void solve(int d, int s, int l) {
    if (d == N+1) {
        if (abs(s-l) < _min) _min = abs(s-l);
        return;
    }
    if (start.size() < N/2) {
        start.push_back(d);
        int sum = 0;
        for (int i=0; i<start.size()-1; i++)
            sum += S[start[i]][d]+S[d][start[i]];
        solve(d+1, s+sum, l);
        start.pop_back();
    }
    if (link.size() < N/2) {
        link.push_back(d);
        int sum = 0;
        for (int i=0; i<link.size()-1; i++)
            sum += S[link[i]][d]+S[d][link[i]];
        solve(d+1, s, l+sum);
        link.pop_back();
    }
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++)
        cin >> S[i][j];
    solve(1, 0, 0);
    cout << _min;
    return 0;
}