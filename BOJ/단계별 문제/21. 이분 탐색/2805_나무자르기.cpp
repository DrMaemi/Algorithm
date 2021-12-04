#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int N, M;
int trees[1000000];

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> trees[i];
    sort(trees, trees+N, greater<>());
    int low = 0, high = trees[0];
    while (low <= high) {
        int mid = (low+high)/2;
        ll sum = 0;
        for (int i=0; i<N; i++) {
            if (trees[i] <= mid) break;
            sum += trees[i]-mid;
        }
        if (M <= sum) low = mid+1;
        else high = mid-1;
    }
    cout << high;
    return 0;
}