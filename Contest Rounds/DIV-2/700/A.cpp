#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int t = 0;
        for (int p=0; p<s.size(); p++) {
            if (!t) {
                for (char c='a'; c<='z'; c++)
                    if (s[p] != c) {
                        s[p] = c; break;
                    }
            }
            else {
                for (char c='z'; c>='a'; c--)
                    if (s[p] != c) {
                        s[p] = c; break;
                    }
            }
            t = (t+1)%2;
        }
        cout << s << "\n";
    }
    return 0;
}

/*
-로직-
문자열을 입력받으면
번갈아가며 다음과 같은 과정을 수행
1. 변동하지 않은 왼쪽 index부터 a~...로 바꿈
2. 변동하지 않은 왼쪽 index부터 z~...로 바꿈(역순)
왼쪽에서 포인터가 계속 움직이면 될 듯.

*/