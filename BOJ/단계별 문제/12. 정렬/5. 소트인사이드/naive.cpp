#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string N;

    cin >> N;
    sort(N.begin(), N.end(), greater<>());
    cout << N;

    return 0;
}