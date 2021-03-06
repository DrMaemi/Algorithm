#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N), p(N), v, vi;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        p[i] = i;
    }
    v.push_back(A[0]); vi.push_back(0);
    for (int i=1; i<N; i++) {
        if (v.back() < A[i]) {
            p[i] = vi.back();
            v.push_back(A[i]); vi.push_back(i);
            continue;
        }
        auto it = lower_bound(v.begin(), v.end(), A[i]);
        *it = A[i];
        int idx = it-v.begin();
        vi[idx] = i;
        if (idx) p[i] = vi[idx-1];
    }
    cout << v.size() << "\n";
    stack<int> out;
    int i = vi.back();
    out.push(i);
    for (; p[i]!=i; i=p[i])
        out.push(p[i]);
    while (!out.empty()) {
        cout << A[out.top()] << " ";
        out.pop();
    }
    return 0;
}