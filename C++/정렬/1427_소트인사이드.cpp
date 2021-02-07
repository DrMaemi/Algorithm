#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string number;

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> number;
    sort(number.begin(), number.end(), greater<>());
    cout << number;
    return 0;
}