#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct L {
    int x, y;
};

bool compare(L& a, L& b) {
    if (a.y != b.y)
        return a.y < b.y;

    return a.x < b.x;
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