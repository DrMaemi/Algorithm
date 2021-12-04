// DrMaemi - 2020KB, 44ms
#include <iostream>
using namespace std;

int main() {
    int N, n = 0;

    cin >> N;

    for (int i=666; ; i++) {
        int x = i, cnt = 0;

        do {
            if (x%10 == 6) {
                cnt++;

                if (cnt == 3) {
                    n++;
                    break;
                }
            }

            else {
                cnt = 0;
            }
        } while (x /= 10);

        if (n == N) {
            cout << i;
            break;
        }
    }

    return 0;
}