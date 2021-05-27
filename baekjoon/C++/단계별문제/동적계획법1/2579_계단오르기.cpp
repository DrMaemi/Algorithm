#include <iostream>

#define MAX 300

using namespace std;

int depth;
int stairs[MAX], sums[MAX][2];

int main(void) {
    cin >> depth;
    for (int i=0; i<depth; i++) {
        cin >> stairs[i];
    }
    sums[0][0] = sums[0][1] = stairs[0];
    sums[1][0] = stairs[1];
    sums[1][1] = stairs[0]+stairs[1];
    for (int i=2; i<depth; i++) {
        sums[i][0] = max(sums[i-2][0], sums[i-2][1])+stairs[i];
        sums[i][1] = sums[i-1][0]+stairs[i];
    }
    cout << max(sums[depth-1][0], sums[depth-1][1]);
    return 0;
}