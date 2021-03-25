#include <iostream>
using namespace std;

struct Node {
    int v;
    Node* l;
    Node* r;
    void insert(int _v) {
        if (_v < v)
            if (l == NULL) {
                l = new Node();
                l->v = _v;
            }
            else l->insert(_v);
        else
            if (r == NULL) {
                r = new Node();
                r->v = _v;
            }
            else r->insert(_v);
    }
};

void post_order(Node* N) {
    if (N == NULL) return;
    post_order(N->l);
    post_order(N->r);
    cout << N->v << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Node* R = new Node();
    cin >> R->v;
    int v;
    while (cin >> v) R->insert(v);
    post_order(R);
    return 0;
}