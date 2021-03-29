#include <iostream>
#include <map>
using namespace std;
#define div 1000000007
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        ll ans = 1;
        while (--k > 1) {
            ans = (ans+n)/div? (ans+n)%div: ans+n;
        }
        n--;
        ans = (ans+n)/div? (ans+n)%div: ans+n;
        cout << ans << "\n";
    }
    return 0;
}

/*
-로직-
plane이 3개이고 D(4)를 발사하면,
D(3)가 3개가 만들어지고
D(2)가 2개 만들어지고


plane이 n개, D(k)를 발사하면
D(k-1)가 n개
D(k-2)가 n-1개
...
D(1)이 

*/