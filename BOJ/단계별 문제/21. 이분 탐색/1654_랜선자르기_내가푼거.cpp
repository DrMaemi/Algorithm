#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int K, N;
ll* lans;

int solve(ll low, ll high) {
    ll mid, made;
    while (low <= high) {
        made = 0;
        mid = (low+high)/2;
        for (int i=0; i<K; i++) {
            made += lans[i]/mid;
        }
        if (N <= made) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return low-1;
}

int main(void) {
    cin >> K >> N;
    lans = (ll*)malloc(sizeof(ll)*K);
    for (int i=0; i<K; i++) {
        cin >> lans[i];
    }
    sort(lans, lans+K);
    cout << solve(1, lans[K-1]);
    return 0;
}