#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;

    vector<int> in(N), ans(N, -1);
    for (int i=0; i<N; i++)
        cin >> in[i];

    stack<int> stk;
    for (int i=0; i<N; i++) {
        while (!stk.empty() && in[stk.top()] < in[i]) {
            ans[stk.top()] = in[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i: ans)
        cout << i << " ";
        
    return 0;
}