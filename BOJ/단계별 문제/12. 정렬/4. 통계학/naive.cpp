#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> v;

struct P {
    int n, cnt;
};

double mean() {
    double m = 0;

    for (int e: v)
        m += e;

    return round(m/v.size());
}

int median() {
    return v[v.size()/2];
}

int mode() {
    int n = v[0], cnt = 1;
    vector<P> cnts;

    for (int i=1; i<v.size(); i++) {
        if (v[i] != n) {
            cnts.push_back({n, cnt});
            n = v[i];
            cnt = 1;
        }

        else cnt++;
    }

    cnts.push_back({n, cnt});
    sort(cnts.begin(), cnts.end(),
        [](const P& a, const P& b) {
            if (a.cnt != b.cnt)
                return a.cnt > b.cnt;

            return a.n < b.n;
        }
    );

    return cnts[0].cnt != cnts[1].cnt? cnts[0].n: cnts[1].n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _min = 4001, _max = -4001;

    cin >> N;
    for (int i=0; i<N; i++) {
        int tmp;

        cin >> tmp;
        v.push_back(tmp);
        _min = tmp < _min? tmp: _min;
        _max = _max < tmp? tmp: _max;
    }

    sort(v.begin(), v.end());

    cout << mean() << "\n";
    cout << median() << "\n";
    cout << mode() << "\n";
    cout << _max-_min << "\n";

    return 0;
}