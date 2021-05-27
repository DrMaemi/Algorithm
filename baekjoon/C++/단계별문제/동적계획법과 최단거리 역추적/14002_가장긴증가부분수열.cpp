#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N), m(N, 1), p(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
        p[i] = i;
    }
    int _max = 0, _max_i = 0;
    for (int i=1; i<N; i++)
        for (int j=0; j<i; j++)
            if (A[j] < A[i])
                if (m[i] < m[j]+1) {
                    m[i] = m[j]+1;
                    p[i] = j;
                    if (_max < m[i]) {
                        _max = m[i];
                        _max_i = i;
                    }
                }
    vector<int> out;
    int ci = _max_i, ni = p[_max_i];
    while (ci != ni) {
        out.push_back(A[ci]);
        ci = ni; ni = p[ci];
    }
    out.push_back(A[ci]);
    cout << m[_max_i] << "\n";
    for (auto it=out.rbegin(); it!=out.rend(); it++)
        cout << *it << " ";
    return 0;
}