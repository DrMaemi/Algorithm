#include <iostream>
#include <vector>
using namespace std;
struct L { int r, c; };

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<string> m(N);
        vector<L> v, add(2);
        for (int r=0; r<N; r++) {
            cin >> m[r];
            for (int c=0; c<N; c++)
                if (m[r][c] == '*') v.push_back({r, c});
        }
        if (v[0].r == v[1].r) {
            if (v[0].r+1 < N) {
                add[0] = {v[0].r+1, v[0].c};
                add[1] = {v[1].r+1, v[1].c};
            }
            else {
                add[0] = {v[0].r-1, v[0].c};
                add[1] = {v[1].r-1, v[1].c};
            }
        }
        else if (v[0].c == v[1].c) {
            if (v[0].c+1 < N) {
                add[0] = {v[0].r, v[0].c+1};
                add[1] = {v[1].r, v[1].c+1};
            }
            else {
                add[0] = {v[0].r, v[0].c-1};
                add[1] = {v[1].r, v[1].c-1};
            }
        }
        else {
            add[0] = {v[0].r, v[1].c};
            add[1] = {v[1].r, v[0].c};
        }
        for (L l: add) {
            // printf("add (%d, %d)\n", l.r, l.c);
            m[l.r][l.c] = '*';
        }
        for (string s: m) cout << s << "\n";
    }
    return 0;
}