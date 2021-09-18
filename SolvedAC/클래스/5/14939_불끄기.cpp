#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> map, simul;

void press(int y, int x) {
    simul[y] ^= (1 << (9-x));
    if (y) simul[y-1] ^= (1 << (9-x));
    if (y < 9) simul[y+1] ^= (1 << (9-x));
    if (x) simul[y] ^= (1 << (10-x));
    if (x < 9) simul[y] ^= (1 << (8-x));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map.resize(10, 0);
    for (int i=0; i<10; i++) {
        string in; cin >> in;
        for (int j=9; j>=0; j--)
            if (in[j] == 'O')
                map[i] |= (1 << j);
    }
    int r = 101;
    for (int _case=(1<<10)-1; _case>=0; _case--) {
        simul = map;
        int cnt = 0;
        for (int x=0; x<10; x++)
            if (_case & (1 << x)) {
                press(0, x);
                cnt++;
            }
        for (int y=1; y<10; y++)
            for (int x=0; x<10; x++)
                if (simul[y-1] & (1 << (9-x))) {
                    press(y, x);
                    cnt++;
                }
        if (!simul[9])
            r = min(r, cnt);
    }
    if (r == 101)
        cout << -1;
    else
        cout << r;
    return 0;
}