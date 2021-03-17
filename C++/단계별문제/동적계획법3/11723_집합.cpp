#include <iostream>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int M; cin >> M;
    int bits = 0;
    while (M--) {
        string cd; int n;
        cin >> cd;
        if (cd == "all")
            bits = (1 << 21)-1;
        else if (cd == "empty")
            bits = 0;
        else {
            cin >> n;
            if (cd == "add")
                bits |= (1 << n);
            else if (cd == "remove")
                bits &= ~(1 << n);
            else if (cd == "check")
                cout << (bits & (1 << n)? 1: 0) << "\n";
            else if (cd == "toggle")
                bits ^= (1 << n);
        }
    }
    return 0;
}