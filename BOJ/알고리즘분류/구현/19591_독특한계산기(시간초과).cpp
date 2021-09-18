#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define V vector
#define S string
#define PQ priority_queue<T, V<T>, cmp>
typedef long long ll;
struct T { int p, i; ll v; };

struct cmp {
    bool operator()(T& _1, T& _2) {
        if (_1.p != _2.p) return _1.p > _2.p;
        if (_1.v != _2.v) return _1.v < _2.v;
        return _1.i > _2.i;
    }
};

ll to_int(S& s) {
    ll r = 0;
    bool neg;
    for (char c: s) {
        if (c == '-') neg = 1;
        else r = 10*r+c-'0';
    }
    return (neg? -1: 1)*r;
}

V<V<S>> split(S& s) {
    V<V<S>> r(2);
    int start = s[0] == '-'? 1: 0;
    if (start)
        r[1].push_back("-");
    int p = start;
    for (int i=start+1; i<s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            r[0].push_back(s.substr(p, i-p));
            r[1].push_back(s.substr(i, 1));
            p = ++i;
        }
    }
    r[0].push_back(s.substr(p));
    if (r[0].size() == r[1].size()) {
        r[0][0] = '-'+r[0][0];
        r[1].erase(r[1].begin());
    }
    return r;
}

void print_numbers(V<ll>& numbers) {
    cout << "print_numbers():\n";
    for (ll x: numbers)
        cout << x << " ";
    cout << "\n";
}

void print_operators(V<S>& operators) {
    cout << "print_operators():\n";
    for (S op: operators)
        cout << op << " ";
    cout << "\n";
}

int main() {
    /* cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0); */
    S s; cin >> s;
    V<V<S>> splited = split(s);
    /* for (V<S> vs: splited) {
        for (S str: vs)
            cout << str << " ";
        cout << "\n";
    } */
    V<ll> numbers;
    for (S number: splited[0])
        numbers.push_back(to_int(number));
    while (!splited[1].empty()) {
        PQ pq;
        for (int i=0; i<splited[1].size(); i++) {
            S op = splited[1][i];
            if (op == "/")
                pq.push({0, i, numbers[i]/numbers[i+1]});
            else if (op == "*")
                pq.push({1, i, numbers[i]*numbers[i+1]});
            else if (op == "+")
                pq.push({2, i, numbers[i]+numbers[i+1]});
            else if (op == "-")
                pq.push({2, i, numbers[i]-numbers[i+1]});
        }
        T t = pq.top();
        auto it = numbers.begin()+t.i;
        numbers.erase(it, it+2);
        numbers.insert(it, t.v);
        splited[1].erase(splited[1].begin()+t.i);
        print_numbers(numbers);
        print_operators(splited[1]);
    }
    cout << numbers.front();
    return 0;
}