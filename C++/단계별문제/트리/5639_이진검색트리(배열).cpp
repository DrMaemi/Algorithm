#include <iostream>
using namespace std;

struct Node { int l, r; } N[1000001];

void post_order(int r) {
    if (r == 0) return;
    post_order(N[r].l);
    post_order(N[r].r);
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int root, n; cin >> root;
    while (cin >> n) {
        int cur = root;
        while (1)
            if (n < cur)
                if (N[cur].l)
                    cur = N[cur].l;
                else {
                    N[cur].l = n;
                    break;
                }
            else
                if (N[cur].r)
                    cur = N[cur].r;
                else {
                    N[cur].r = n;
                    break;
                }
    }
    post_order(root);
    return 0;
}