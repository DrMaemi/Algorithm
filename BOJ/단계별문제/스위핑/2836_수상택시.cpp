#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct P { int a, b; };

bool cmp(P& i, P& j) {
    return i.a > j.a;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<P> A;
    while (N--) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            A.push_back({a, b});
    }
    sort(A.begin(), A.end(), cmp);
    ll ans = M;
    if (!A.empty()) {
        int r = A[0].a, l = A[0].b;
        for (int i=1; i<A.size(); i++) {
            if (l <= A[i].a) // 합승 가능하면
                l = min(l, A[i].b);
            else { // 합승 불가, 내려준 뒤 해당 사람 태움
                ans += 2*(r-l);
                r = A[i].a; l = A[i].b;
            }
        }
        ans += 2*(r-l);
    }
    cout << ans;
    return 0;
}