// DrMaemi - 2020KB, 0ms
#include <iostream>
using namespace std;

int main() {
    int N, ans = 0;
    char c;

    cin >> N;
    
    for (int i=0; i<N; i++) {
        cin >> c;
        ans += c-'0';
    }

    cout << ans;

    return 0;
}