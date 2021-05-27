#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    vector<int> values;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int value;
        cin >> value;
        values.push_back(value);
    }
    int answer = 0;
    for (int i=n-1; i>=0; i--) {
        if (values[i] <= k) {
            answer += k/values[i];
            k %= values[i];
        }
        if (k == 0) break;
    }
    cout << answer;
    return 0;
}