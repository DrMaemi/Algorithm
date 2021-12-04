// DrMaemi - 2020KB, 12ms
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, ans = 0;
    
    cin >> N;

    for (int n=1; n<N; n++) {
        int sum = n;

        for (char i: to_string(n)) {
            sum += i-'0';
        }

        if (sum == N) {
            ans = n;
            break;
        }
    }

    cout << ans;
    return 0;
}
