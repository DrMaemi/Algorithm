// DrMaemi - 2024KB, 0ms
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, ans;
    cin >> a >> b;

    for (int i=2; i>=0; i--) {
        if (a[i] > b[i]) {
            ans = a;
            break;
        }

        else if (a[i] < b[i]) {
            ans = b;
            break;
        }
    }

    for (int i=2; i>=0; i--)
        cout << ans[i];
    
    return 0;
}