#include <iostream>
using namespace std;

int DP[1002][1002] = {0};

int main() {
    string a, b;
    
    cin >> a >> b;
    a = " "+a;
    b = " "+b;
    
    int len_a = a.length();
    int len_b = b.length();
    for (int i=1; i<len_a; i++)
        for (int j=1; j<len_b; j++)
            if (a[i] == b[j])
                DP[i][j] = DP[i-1][j-1]+1;
            
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);

    cout << DP[len_a-1][len_b-1];
    return 0;
}