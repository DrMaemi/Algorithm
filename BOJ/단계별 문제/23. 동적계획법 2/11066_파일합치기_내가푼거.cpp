#include <iostream>
#include <vector>
#include <cstring>

#define MAX 501

using namespace std;

int dp[MAX][MAX] = { 0, };

int main(void) {
    int testcase;
    vector<int> costs;
    vector<int> answers;
    cin >> testcase;
    for (int tc=0; tc<testcase; tc++) {
        int chapter;
        cin >> chapter;
        for (int ct=0; ct<chapter; ct++) {
            int cost;
            cin >> cost;
            costs.push_back(cost);
        }
        for (int i=0; i<chapter-1; i++) {
            dp[i][i+1] = costs[i]+costs[i+1];
        }
        while (!dp[0][chapter-1]) {
            for (int i=0; i<chapter; ) {
                
            }
        }
        answers.push_back(dp[0][chapter-1]);
        memset(dp, 0, sizeof(dp));
    }
    for (int i=0; i<answers.size(); i++) {
        cout << 2*answers[i] << "\n";
    }
    return 0;
}