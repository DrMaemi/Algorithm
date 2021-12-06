// DrMaemi - 7584ms, 76ms
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(string& a, string& b) {
    if (a.length() != b.length())
        return a.length() < b.length();

    return a < b;
}

int main() {
    int N;
    vector<string> words;

    cin >> N;
    for (int i=0; i<N; i++) {
        string word;

        cin >> word;
        words.push_back(word);
    }

    set<string> s(words.begin(), words.end());
    words.assign(s.begin(), s.end());
    sort(words.begin(), words.end(), compare);

    for (string word: words)
        cout << word << "\n";

    return 0;
}