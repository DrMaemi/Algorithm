#include <iostream>
using namespace std;

int N;
string S;

void dfs() {
    int l = S.length();
    if (l == N) {
        cout << S;
        exit(0);
    }
    for (char i='1'; i<'4'; i++) {
        S.push_back(i); l++;
        bool bad = 0;
        for (int _l=1; _l<=l/2; _l++)
            if (S.substr(l-_l) == S.substr(l-2*_l, _l)) {
                bad = 1;
                break;
            }
        if (!bad)
            dfs();
        S.pop_back(); l--;
    }
}

int main() {
    cin >> N;
    dfs();
    return 0;
}