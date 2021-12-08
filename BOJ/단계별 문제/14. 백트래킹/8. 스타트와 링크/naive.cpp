#include <iostream>
#include <vector>
using namespace std;

int N, ans = 40000;
int S[20][20];
vector<int> s, l;

void f(int i, int ssum, int lsum) {
    if (i == N) {
        int dff = abs(ssum-lsum);

        ans = dff < ans? dff: ans;
        return;
    }

    if (s.size() < N/2) {
        int sum = 0;

        s.push_back(i);
        for (int j: s)
            sum += S[i][j]+S[j][i];

        f(i+1, ssum+sum, lsum);
        s.pop_back();
    }

    if (l.size() < N/2) {
        int sum = 0;

        l.push_back(i);
        for (int j: l)
            sum += S[i][j]+S[j][i];

        f(i+1, ssum, lsum+sum);
        l.pop_back();
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> S[i][j];

    f(0, 0, 0);
    cout << ans;

    return 0;
}