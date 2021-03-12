#include <iostream>
using namespace std;
#define MAX 2500

string s;
bool P[MAX][MAX];
int CM[MAX];

int dp(int r) {
    if (P[0][r])
        return 1;
    if (CM[r] == MAX)
        for (int i=r-1; i>=0; i--)
            CM[r] = min(CM[r], dp(i)+(P[i+1][r]? 1: MAX));
    return CM[r];
}

int main() {
    cin >> s;
    int len = s.length();
    for (int i=0; i<len; i++)
        P[i][i] = 1;
    for (int i=0; i<len-1; i++)
        if (s[i] == s[i+1])
            P[i][i+1] = 1;
    for (int d=2; d<len; d++)
        for (int l=0; l<len-d; l++) {
            int r = l+d;
            if (s[l] == s[r] && P[l+1][r-1])
                P[l][r] = 1;
        }
    fill(CM, CM+len, MAX);
    cout << dp(len-1);
    return 0;
}