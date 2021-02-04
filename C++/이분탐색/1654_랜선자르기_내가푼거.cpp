#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
long long* lans;

int solve(long long low, long long high) {
    long long mid, made;
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
    lans = (long long*)malloc(sizeof(long long)*K);
    for (int i=0; i<K; i++) {
        cin >> lans[i];
    }
    sort(lans, lans+K);
    cout << solve(1, lans[K-1]);
    return 0;
}