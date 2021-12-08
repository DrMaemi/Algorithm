#include <iostream>
#include <vector>
using namespace std;

struct L { int i, j; };

int b[9][9], max_depth;
bool r[9][10] = {0};
bool c[9][10] = {0};
bool p[3][3][10] = {0};
vector<L> v;
bool found = 0;

void f(int d) {
    if (d == max_depth) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << b[i][j] << " ";
            }
            
            cout << "\n";
        }

        found = 1;
        return;
    }

    int i = v[d].i, j = v[d].j;
    for (int n=1; n<=9; n++) {
        if (!r[i][n] && !c[j][n] && !p[i/3][j/3][n]) {
            b[i][j] = n;
            r[i][n] = c[j][n] = p[i/3][j/3][n] = 1;
            f(d+1);
            r[i][n] = c[j][n] = p[i/3][j/3][n] = 0;
        }

        if (found) break;
    }
}

int main() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> b[i][j];

            if (b[i][j]) {
                r[i][b[i][j]] = 1;
                c[j][b[i][j]] = 1;
                p[i/3][j/3][b[i][j]] = 1;
            }
            
            else v.push_back({i, j});
        }
    }

    max_depth = v.size();
    f(0);

    return 0;
}