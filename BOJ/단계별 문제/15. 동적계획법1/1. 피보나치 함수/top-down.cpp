#include <iostream>
using namespace std;

int calls[41][2] = {{1, 0}, {0, 1}, {0}};

int* f(int n) {
    if (calls[n][0] || calls[n][1] || n < 2)
        return calls[n];

    else {
        for (int i=0; i<2; i++)
            calls[n][i] = f(n-1)[i]+f(n-2)[i];
        
        return calls[n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;

    cin >> T;
    while (T--) {
        int n;

        cin >> n;
        int* r = f(n);
        cout << r[0] << " " << r[1] << "\n";
    }

    return 0;
}