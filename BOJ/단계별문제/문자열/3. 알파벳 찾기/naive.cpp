// DrMaemi - 2024KB, 0ms
#include <iostream>
#include <string>
using namespace std;

int main() {
    string atoz = "", s;

    cin >> s;

    for (char c='a'; c<='z'; c++) {
        atoz += c;
    }

    for (char c: atoz) {
        cout << (int)s.find(c) << " ";
    }

    return 0;
}