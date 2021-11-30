// DrMaemi - 2024KB, 0ms
#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, R;
    string S;

    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> R >> S;

        for (char c: S) {
            for (int r=0; r<R; r++) {
                cout << c;
            }
        }
        
        cout << endl;
    }

    return 0;
}