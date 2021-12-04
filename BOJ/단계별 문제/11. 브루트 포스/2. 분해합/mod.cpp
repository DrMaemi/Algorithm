// DrMaemi - 2020KB, 4ms
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, ans = 0;

    cin >> N;

    for (int n=1; n<N; n++) {
        int sum = n, nn = n;

        do {
            sum += nn%10;
        } while (nn /= 10);

        if (sum == N) {
            ans = n;
            break;
        }
    }
    
    cout << ans;
    return 0;
}
