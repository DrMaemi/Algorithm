#include <iostream>
#include <climits>
using namespace std;

#define MAX 2001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))

int N;
int tunes[MAX];
int memo[MAX][MAX];

int main(void) {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> tunes[i];
    }
    for (int i=0; i<=N; i++) {
        fill(memo[i], memo[i]+(N+1), INT_MAX);
    }
    memo[0][1] = memo[1][0] = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == j) continue;
            int next = max(i, j)+1;
            if (!i || !j) tunes[0] = tunes[next];
            memo[next][j] = min(
                memo[next][j],
                memo[i][j]+abs(tunes[next]-tunes[i])
                );
            memo[i][next] = min(
                memo[i][next],
                memo[i][j]+abs(tunes[next]-tunes[j])
                );
        }
    }
    int answer = INT_MAX;
    for (int i=0; i<N; i++) {
        answer = min(answer, memo[N][i]);
        answer = min(answer, memo[i][N]);
    }
    cout << answer;
    return 0;
}