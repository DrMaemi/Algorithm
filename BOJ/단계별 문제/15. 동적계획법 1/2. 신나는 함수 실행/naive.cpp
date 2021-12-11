#include <iostream>
using namespace std;

int calculated[21][21][21];
bool called[21][21][21] = {0};

int w(int a, int b, int c) {
    int r;
    
    if (a <= 0 || b <= 0 || c <= 0)
        r = 1;

    else if (20 < a || 20 < b || 20 < c)
        r = w(20, 20, 20);

    else if (called[a][b][c])
        r = calculated[a][b][c];

    else {
        if (a < b && b < c)
            r = w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c);

        else
            r = w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1);

        called[a][b][c] = 1;
        calculated[a][b][c] = r;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        int a, b, c;

        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }

    return 0;
}