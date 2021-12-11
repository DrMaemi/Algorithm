#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int DP[3] = {0};

    cin >> N;
    for (int i=0; i<N; i++) {
        int n;
        int _DP[3];

        for (int j=0; j<3; j++)
            _DP[j] = DP[j];

        cin >> n;
        DP[0] = *max_element(_DP, _DP+3);
        DP[1] = _DP[0]+n;
        DP[2] = _DP[1]+n;
    }

    cout << *max_element(DP, DP+3);
    return 0;
}