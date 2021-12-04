#include <iostream>
#include <vector>
using namespace std;

struct P {
    int w, h;
};

int main() {
    int N;
    vector<P> v;
    
    cin >> N;

    for (int i=0; i<N; i++) {
        P p;

        cin >> p.w >> p.h;
        v.push_back(p);
    }

    for (int i=0; i<N; i++) {
        int ans = 1;

        for (int j=0; j<N; j++) {
            if (i != j && v[i].w < v[j].w && v[i].h < v[j].h) {
                ans++;
            }
        }

        cout << ans << " ";
    }

    return 0;
}
