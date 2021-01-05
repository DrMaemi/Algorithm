#include <iostream>

using namespace std;

template<class T>
void func(T &arg);

int main(void) {
    int arg = 5;
    cout << "before func(), arg: " << arg << "\n";
    func(arg);
    cout << "after func(), arg: " << arg << "\n";
    return 0;
}

template<class T>
void func(T &arg) {
    cout << "in func(), --arg: " << --arg << "\n";
}