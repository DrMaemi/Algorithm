#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    int calls[41][2] = {0};

    calls[0][0] = calls[1][1] = 1;
    calls[0][1] = calls[1][0] = 0;
    for (int i=2; i<=40; i++) {
        calls[i][0] = calls[i-1][0]+calls[i-2][0];
        calls[i][1] = calls[i-1][1]+calls[i-2][1];
    }

    cin >> T;
    while (T--) {
        int i;

        cin >> i;
        cout << calls[i][0] << " " << calls[i][1] << "\n";
    }

    return 0;
}