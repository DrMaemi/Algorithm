#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    stack<int> s;

    cin >> N;
    vector<int> v(N), ans(N, -1);
    
    for (int i=0; i<N; i++)
        cin >> v[i];

    for (int i=0; i<N; i++) {
        while (!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = v[i];
            s.pop();
        }

        s.push(i);
    }

    for (int x: ans)
        cout << x << " ";

    return 0;
}