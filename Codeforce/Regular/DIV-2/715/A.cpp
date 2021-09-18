#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A, B;
        while (N--) {
            int n; cin >> n;
            if (n & 1) A.push_back(n);
            else B.push_back(n);
        }
        for (int x: A) cout << x << " ";
        for (int x: B) cout << x << " ";
        cout << "\n";
    }
    return 0;
}