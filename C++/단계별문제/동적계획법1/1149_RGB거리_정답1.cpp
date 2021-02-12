#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int house[MAX][3] = {0, };

int main(void) {
    int N;
    int cost[3];
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i-1][1], house[i-1][2]) + cost[0];
        house[i][1] = min(house[i-1][0], house[i-1][2]) + cost[1];
        house[i][2] = min(house[i-1][0], house[i-1][1]) + cost[2];
    }
    cout << min(house[N][0], min(house[N][1], house[N][2]));
    return 0;
}