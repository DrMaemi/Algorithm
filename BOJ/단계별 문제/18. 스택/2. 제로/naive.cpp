#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;
    vector<int> buff;

    cin >> K;
    for (int i=0; i<K; i++) {
        int n;

        cin >> n;
        if (n) buff.push_back(n);
        else buff.pop_back();
    }

    cout << accumulate(buff.begin(), buff.end(), 0);
    return 0;
}