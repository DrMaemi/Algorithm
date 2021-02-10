#include <iostream>
using namespace std;

bool is_factor(int n, int m) {
    if (m/n && !(m%n)) return true;
    return false;
}

bool is_multiple(int n, int m) {
    if (n/m && !(n%m)) return true;
    return false;
}

const char* verify(int n, int m) {
    if (is_factor(n, m))
        return "factor";
    else if (is_multiple(n, m))
        return "multiple";
    return "neither";
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    while (1) {
        cin >> n >> m;
        if (!n && !m) break;
        cout << verify(n, m) << "\n";
    }
    return 0;
}