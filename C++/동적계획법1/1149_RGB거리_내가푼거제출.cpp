#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000
#define parent(x) (x-1)/2

using namespace std;

int n;
int answer = 1000000;
int sum = 0;
vector<int> stack;
int costs[MAX][3];

void dfs(int pos) {
    if (pos == n) {
        answer = sum;
        return;
    }
    for (int i=0; i<3; i++) {
        if (pos != 0 && i == stack[pos-1]) continue;
        sum += costs[pos][i];
        if (sum >= answer) {
            sum -= costs[pos][i];
            continue;
        }
        stack.push_back(i);
        dfs(pos+1);
        stack.pop_back();
        sum -= costs[pos][i];
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin >> costs[i][j];
        }
    }
    dfs(0);
    cout << answer;
    return 0;
}