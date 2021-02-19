#include <iostream>
using namespace std;

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    int n;
    for (int i=1; i<=N; i++) {
        cin >> n;
        if (i%2 != n%2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}