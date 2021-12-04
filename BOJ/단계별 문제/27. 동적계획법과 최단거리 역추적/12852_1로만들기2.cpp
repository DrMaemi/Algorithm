#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int CM[1000001], P[1000001];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    fill(CM, CM+N+1, -1);
    CM[N] = 0;
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int s = q.size();
        while (s--) {
            int n = q.front(); q.pop();
            if (n == 1) {
                cout << CM[1] << "\n";
                stack<int> p;
                while (n) {
                    p.push(n);
                    n = P[n];
                }
                while (!p.empty()) {
                    cout << p.top() << " ";
                    p.pop();
                }
                return 0;
            }
            if (!(n%3) && CM[n/3] == -1) {
                q.push(n/3);
                P[n/3] = n;
                CM[n/3] = CM[n]+1;
            }
            if (!(n%2) && CM[n/2] == -1) {
                q.push(n/2);
                P[n/2] = n;
                CM[n/2] = CM[n]+1;
            }
            if (n && CM[n-1] == -1) {
                q.push(n-1);
                P[n-1] = n;
                CM[n-1] = CM[n]+1;
            }
        }
    }
    return 0;
}