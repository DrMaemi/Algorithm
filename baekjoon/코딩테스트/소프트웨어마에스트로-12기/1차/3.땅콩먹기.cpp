#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct P { int p, d; };

int N, M, E;
vector<P> v;

bool compare(P _1, P _2) {
    return _1.d < _2.d;
}

int main() {
    cin >> N >> M >> E;
    for (int i=0; i<N; i++) {
        int p; cin >> p;
        v.push_back({p, abs(E-p)});
    }
    sort(v.begin(), v.end(), compare);
    int _min = E, _max = E;
    for (int i=0; i<M; i++) {
        _min = min(_min, v[i].p);
        _max = max(_max, v[i].p);
    }
    cout << _max-_min;
    return 0;
}