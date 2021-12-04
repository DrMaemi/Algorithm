// DrMaemi - 2020KB, 56ms
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, order = 0;

    cin >> N;

    for (int n=666; ; n++) {
        string s = to_string(n);
        int cnt = 0;

        for (char c: s) {
            if (c == '6') {
                cnt++;

                if (cnt == 3) {
                    order++;
                    break;
                }
            }

            else {
                cnt = 0;
            }
        }

        if (order == N) {
            cout << s;
            break;
        }
    }

    return 0;
}