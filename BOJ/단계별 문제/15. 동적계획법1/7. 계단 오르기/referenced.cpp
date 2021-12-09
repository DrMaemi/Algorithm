#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    int D0 = 0, D1 = 0, D2 = 0;

    cin >> N;
    for (int i=0; i<N; i++) {
        int n;
        int _D0 = D0, _D1 = D1, _D2 = D2;

        cin >> n;
        D0 = max(_D1, _D2);
        D1 = _D0+n;
        D2 = _D1+n;
    }

    cout << max(D1, D2);
    return 0;
}