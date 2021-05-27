#include <iostream>
#include <vector>
#include <cstring>

#define MAX 21

using namespace std;

int memo[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
vector<vector<int>> answers;

int w(int a, int b, int c);

int main(void) {
    ios::sync_with_stdio(false);
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        vector<int> answer = {a, b, c, w(a, b, c)};
        answers.push_back(answer);
    }
    for (int i=0; i<answers.size(); i++) {
        printf("w(%d, %d, %d) = %d\n",
            answers[i][0], answers[i][1], answers[i][2], answers[i][3]);
    }
    return 0;
}

int w(int a, int b, int c) {
    if (a<=0 || b<=0 || c<=0) {
        return 1;
    }
    else if (a>20 || b>20 || c>20) {
        return w(20, 20, 20);
    }
    else if (visited[a][b][c]) {
        return memo[a][b][c];
    }
    else if (a<b && b<c) {
        int e1, e2, e3;
        if (visited[a][b][c-1]) {
            e1 = memo[a][b][c-1];
        }
        else {
            e1 = w(a, b, c-1);
            visited[a][b][c-1] = true;
            memo[a][b][c-1] = e1;
        }
        if (visited[a][b-1][c-1]) {
            e2 = memo[a][b-1][c-1];
        }
        else {
            e2 = w(a, b-1, c-1);
            visited[a][b-1][c-1] = true;
            memo[a][b-1][c-1] = e2;
        }
        if (visited[a][b-1][c]) {
            e3 = memo[a][b-1][c];
        }
        else {
            e3 = w(a, b-1, c);
            visited[a][b-1][c] = true;
            memo[a][b-1][c] = e3;
        }
        return e1 + e2 - e3;
    }
    else {
        int e1, e2, e3, e4;
        if (visited[a-1][b][c]) {
            e1 = memo[a-1][b][c];
        }
        else {
            e1 = w(a-1, b, c);
            visited[a-1][b][c] = true;
            memo[a-1][b][c] = e1;
        }
        if (visited[a-1][b-1][c]) {
            e2 = memo[a-1][b-1][c];
        }
        else {
            e2 = w(a-1, b-1, c);
            visited[a-1][b-1][c] = true;
            memo[a-1][b-1][c] = e2;
        }
        if (visited[a-1][b][c-1]) {
            e3 = memo[a-1][b][c-1];
        }
        else {
            e3 = w(a-1, b, c-1);
            visited[a-1][b][c-1];
            memo[a-1][b][c-1] = e3;
        }
        if (visited[a-1][b-1][c-1]) {
            e4 = memo[a-1][b-1][c-1];
        }
        else {
            e4 = w(a-1, b-1, c-1);
            visited[a-1][b-1][c-1] = true;
            memo[a-1][b-1][c-1] = e4;
        }
        return e1 + e2 + e3 - e4;
    }
}