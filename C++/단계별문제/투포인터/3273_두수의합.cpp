#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N, target; cin >> N;
    int m[100000];
    for (int i=0; i<N; i++) cin >> m[i];
    cin >> target; sort(m, m+N);
    int l = 0, r = N-1, answer = 0;
    while (l < r) {
        if (m[l]+m[r] < target) l++;
        else if (m[l]+m[r] > target) r--;
        else {
            answer++; l++; r--;
        }
    }
    cout << answer;
    return 0;
}