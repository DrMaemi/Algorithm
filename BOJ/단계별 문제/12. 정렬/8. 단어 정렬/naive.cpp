// DrMaemi - 4528KB, 60ms
#include <iostream>
#include <vector>
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

    sort(words.begin(), words.end(), compare);

    cout << words[0] << "\n";
    for (int i=1; i<words.size(); i++)
        if (words[i-1] != words[i])
            cout << words[i] << "\n";

    return 0;
}