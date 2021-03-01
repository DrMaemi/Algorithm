#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define V vector
#define S string

S skills;
V<S> combo;
V<bool> after;

int idx(char u) {
    for (int i=0; i<skills.length(); i++)
        if (skills[i] == u)
            return i;
    return -1;
}

void print_skills_and_combo() {
    cout << "skills:\n";
    for (char c: skills)
        cout << c << " ";
    cout << "\ncombo:\n";
    for (int i=0; i<(int)skills.size(); i++) {
        cout << skills[i] << " - ";
        for (char c: combo[i])
            cout << c << " ";
        cout << "\n";
    }
}

void dfs(int sidx, V<char> out) {
    if (combo[sidx].empty() && out.size() != 1) {
        for (char c: out)
            cout << c << " ";
        cout << "\n";
    }
    for (char nx: combo[sidx]) {
        out.push_back(nx);
        dfs(idx(nx), out);
        out.pop_back();
    }
}

int main() {
    S in;
    getline(cin, in);
    for (char c: in)
        if (c != ' ' && c != '\n')
            skills.push_back(c);
    int N; cin >> N;
    combo.resize(skills.length());
    after.resize(skills.length());
    int ii = -1; char pre = '0';
    while (N--) {
        char u, v;
        cin >> u >> v;
        if (pre != u) {
            ii++; pre = u;
        }
        combo[ii].push_back(v);
        after[idx(v)] = 1;
    }
    for (int i=0; i<skills.size(); i++) {
        if (after[i]) continue;
        V<char> out = { skills[i] };
        dfs(i, out);
    }
    return 0;
}