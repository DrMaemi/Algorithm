#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
typedef struct coordinate {
    int x;
    int y;
} cdn;

int N, P;
vector<cdn> pts;
mt19937 rd;

int cnt(cdn _1, cdn _2) {
    int r = 0;
    for (cdn p : pts)
        r += (_2.x-_1.x)*(p.y-_1.y) == (_2.y-_1.y)*(p.x-_1.x);
    return r;
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> P;
    if (N == 1) {
        cout << "possible"; return 0;
    }
    pts.resize(N);
    double target = N*P*0.01;
    for (int i=0; i<N; i++)
        cin >> pts[i].x >> pts[i].y;
    rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> ran(0, N-1);
    for (int l=0; l<150; l++) {
        int i = ran(rd); int j = ran(rd);
        while (i == j) j = ran(rd);
        if (target <= cnt(pts[i], pts[j])) {
            cout << "possible"; return 0;
        }
    }
    cout << "impossible";
    return 0;
}