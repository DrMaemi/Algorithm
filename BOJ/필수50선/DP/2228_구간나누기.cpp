#include <iostream>
using namespace std;
#define MIN -3276800

int arr[101];
int CM[101][51];

int dp(int r, int k) {
    if (!k)
        return 0;
    if (r <= 0)
        return MIN;
    if (CM[r][k] == -1) {
        CM[r][k] = dp(r-1, k);
        int sum = 0;
        for (int i=r; i>0; i--) {
            sum += arr[i];
            CM[r][k] = max(CM[r][k], dp(i-2, k-1)+sum);
        }
    }
    return CM[r][k];
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        fill(CM[i], CM[i]+N/2+1, -1);
    }
    cout << dp(N, M);
    return 0;
}