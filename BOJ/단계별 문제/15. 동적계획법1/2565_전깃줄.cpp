#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Line {
    int A, B;
} L;

int E, m[101];
L l[101];

bool compare(L _1, L _2) {
    return _1.A < _2.A;
}

int main(void) {
    cin >> E;
    for (int i=0; i<E; i++)
        cin >> l[i].A >> l[i].B;
    sort(l, l+E, compare);
    int max_v = 0;
    for (int i=1; i<E; i++) {
        for (int j=0; j<i; j++) {
            if (l[j].B < l[i].B) {
                m[i] = max(m[i], m[j]+1);
            }
        }
        max_v = max(max_v, m[i]);
    }
    cout << E-max_v-1;
    return 0;
}