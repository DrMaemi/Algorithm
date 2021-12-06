#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct P {
    int i, x;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<P> v;

    cin >> N;
    for (int i=0; i<N; i++) {
        int tmp;

        cin >> tmp;
        v.push_back({i, tmp});
    }

    sort(v.begin(), v.end(), [](const P& a, const P& b) {return a.x < b.x;});

    int total_cnt = 1;
    int px = v[0].x;
    for (int i=1; i<v.size(); i++) {
        if (px != v[i].x) {
            total_cnt++;
            px = v[i].x;
        }
    }
    
    vector<int> ans(N);
    ans[v[N-1].i] = total_cnt-1;
    for (int i=N-2; i>=0; i--) {
        ans[v[i].i] = v[i].x == v[i+1].x? ans[v[i+1].i]: ans[v[i+1].i]-1;
    }

    for (int cnt: ans)
        cout << cnt << " ";

    return 0;
}