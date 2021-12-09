#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int DP[1001][3] = {0};

    cin >> N;
    for (int i=1; i<=N; i++) {
        int c[3];

        cin >> c[0] >> c[1] >> c[2];
        for (int j=0; j<3; j++)
            DP[i][j] = min(DP[i-1][(j+1)%3], DP[i-1][(j+2)%3])+c[j];
    }
        
    cout << *min_element(DP[N], DP[N]+3);
    return 0;
}