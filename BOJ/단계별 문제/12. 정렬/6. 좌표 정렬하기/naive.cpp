#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct L {
    int x, y;
};

bool compare(L& a, L& b) {
    if (a.x != b.x)
        return a.x < b.x;

    return a.y < b.y;
}

int main() {
    int N;
    vector<L> v;

    cin >> N;
    for (int i=0; i<N; i++) {
        L l;

        cin >> l.x >> l.y;
        v.push_back(l);
    }

    sort(v.begin(), v.end(), compare);

    for (L l: v)
        cout << l.x << " " << l.y << "\n";

    return 0;
}