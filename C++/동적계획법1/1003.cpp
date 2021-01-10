#include <iostream>
#include <vector>

#define MAX 41

using namespace std;

int zero, one;

vector<int> fibonacci(int n);
bool visited[MAX] = { false, };
vector<vector<int>> memo(MAX);

int main(void) {
    int testcase, n;
    vector<vector<int>> answers;
    cin >> testcase;
    for (int t=0; t<testcase; t++) {
        cin >> n;
        zero = one = 0;
        answers.push_back(fibonacci(n));
    }
    for (auto it=answers.begin(); it!=answers.end(); it++) {
        zero = (*it)[0];
        one = (*it)[1];
        cout << zero << " " << one << "\n";
    }
    return 0;
}

vector<int> fibonacci(int n) {
    if (n == 0) {
        vector<int> result = {1, 0};
        return result;
    }
    else if (n == 1) {
        vector<int> result = {0, 1};
        return result;
    }
    else {
        if (visited[n]) {
            return memo[n];
        }
        visited[n] = true;
        vector<int> r1 = fibonacci(n-1);
        vector<int> r2 = fibonacci(n-2);
        zero = r1[0] + r2[0];
        one = r1[1] + r2[1];
        vector<int> result = {zero, one};
        memo[n] = result;
        return result;
    }
}