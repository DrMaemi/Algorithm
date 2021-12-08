#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, op_cnts[4] = {0};
int _min = INT_MAX, _max = INT_MIN;
vector<int> v, ops;

void f(int d) {
    if (d == v.size()-1) {
        int r = v[0];

        for (int i=1; i<v.size(); i++) {
            if (ops[i-1] == 0) r += v[i];
            else if (ops[i-1] == 1) r -= v[i];
            else if (ops[i-1] == 2) r *= v[i];
            else r /= v[i];
        }

        _min = r < _min? r: _min;
        _max = _max < r? r: _max;
        return;
    }

    for (int i=0; i<4; i++) {
        if (op_cnts[i]) {
            op_cnts[i]--;
            ops.push_back(i);
            f(d+1);
            op_cnts[i]++;
            ops.pop_back();
        }
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int n;

        cin >> n;
        v.push_back(n);
    }

    for (int i=0; i<4; i++)
        cin >> op_cnts[i];

    f(0);
    cout << _max << "\n";
    cout << _min;

    return 0;
}