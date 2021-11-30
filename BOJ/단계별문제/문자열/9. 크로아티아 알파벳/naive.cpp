#include <iostream>
using namespace std;

int main() {
    string croatians[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string word;

    cin >> word;
    for (string croatian: croatians) {
        int idx = word.find(croatian);

        while (idx != string::npos) {
            word.replace(idx, croatian.length(), "#");
            idx = word.find(croatian);
        }
    }

    cout << word.length();
    return 0;
}