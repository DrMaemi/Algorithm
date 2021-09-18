#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct pair {
    string t;
    int n;
} p;
typedef struct result {
    bool f;
    int i;
} r;

int T, n;
vector<p> v;

r search(string t) {
    for (int i=0; i<v.size(); i++) {
        if (v[i].t == t) return {true, i};
    }
    return {false, -1};
}

int solve() {
    int size = v.size();
    if (!size) return 0;
    int answer = 1;
    for (int i=0; i<size; i++)
        answer *= v[i].n+1;
    return answer-1;
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> T;
    string s, t;
    while (T--) {
        cin >> n;
        while (n--) {
            cin >> s >> t;
            r rs = search(t);
            if (rs.f) v[rs.i].n++;
            else v.push_back({t, 1});
        }
        cout << solve() << "\n";
        v.clear();
    }
    return 0;
}