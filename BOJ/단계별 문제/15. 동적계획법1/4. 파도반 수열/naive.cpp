#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    vector<long long> v = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

    for (int i=11; i<=100; i++)
        v.push_back(v[i-5]+v[i-1]);

    cin >> T;
    while (T--) {
        int n;

        cin >> n;
        cout << v[n] << "\n";
    }

    return 0;
}