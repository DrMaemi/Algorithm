#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

long long seq[MAX] = {0, 1, 1, 1, 2, 2, };

void get_seq(int n);

int main(void) {
    int testcase, n;
    vector<long long> answers;
    cin >> testcase;
    for (int t=0; t<testcase; t++) {
        cin >> n;
        if (seq[n]) {
            answers.push_back(seq[n]);
            continue;
        }
        get_seq(n);
        answers.push_back(seq[n]);
    }
    for (int i=0; i<answers.size(); i++) {
        cout << answers[i] << "\n";
    }
    return 0;
}

void get_seq(int n) {
    if (n < 6 || seq[n]) return;
    if (!seq[n-5]) get_seq(n-5);
    if (!seq[n-1]) get_seq(n-1);
    seq[n] = seq[n-5]+seq[n-1];
}

// 1 1 1 2 2 3 4 5 7 9 12 16에서
// 1 2 3 4 5 6 7 8 9 10 11
// 4번째 + 8번째 = 9번째
// n-5번째 + n-1번째 = n번째
// 0 1 1 1 2 2 까지 고정.