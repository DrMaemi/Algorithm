#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000

int N, K;
vector<int> m, p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    int size = max(N, K);
    m.resize(2*size+1, -1); p.resize(2*size+1, -1);
    m[N] = 0; p[N] = N;
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int f = q.front(); q.pop();
        if (f == K) {
            cout << m[f] << "\n";
            vector<int> o;
            for (int k=K; k!=p[k]; k=p[k])
                o.push_back(k);
            cout << N << " ";
            for (auto it=o.rbegin(); it!=o.rend(); it++)
                cout << *it << " ";
            return 0;
        }
        if (f && m[f-1] == -1) {
            m[f-1] = m[f]+1;
            p[f-1] = f;
            q.push(f-1);
        }
        if (f < 2*size && m[f+1] == -1) {
            m[f+1] = m[f]+1;
            p[f+1] = f;
            q.push(f+1);
        }
        if (f <= size && m[2*f] == -1) {
            m[2*f] = m[f]+1;
            p[2*f] = f;
            q.push(2*f);
        }
    }
    return 0;
}