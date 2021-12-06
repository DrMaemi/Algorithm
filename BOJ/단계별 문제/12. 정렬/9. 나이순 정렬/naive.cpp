#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct P {
    int age;
    string name;
};

bool compare(const P& a, const P& b) {
    return a.age < b.age;
}

int main() {
    int N;
    vector<P> v;

    cin >> N;
    for (int i=0; i<N; i++) {
        P p;

        cin >> p.age >> p.name;
        v.push_back(p);
    }

    stable_sort(v.begin(), v.end(), compare);

    for (P p: v)
        cout << p.age << " " << p.name << "\n";

    return 0;
}