#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N);
    int sum = 0;
    for (int i=0; i<N; i++) {
        int n; cin >> n;
        sum += n;
        S[i] = sum;
    }
    int _max = max(0, S[M-1]), _min = 0;
    for (int i=M; i<N; i++) {
        _min = min(_min, S[i-M]);
        _max = max(_max, S[i]-_min);
    }
    cout << _max;
    return 0;
}