#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    stack<char> S;
    string r;
    for (char c: s)
        if ('A' <= c && c <= 'Z') r += c;
        else if (c == '(') S.push(c);
        else if (c == '*' || c == '/') {
            while (!S.empty() && (S.top() == '*' || S.top() == '/')) {
                r += S.top(); S.pop();
            }
            S.push(c);
        }
        else if (c == '+' || c == '-') {
            while (!S.empty() && S.top() != '(') {
                r += S.top(); S.pop();
            }
            S.push(c);
        }
        else if (c == ')') {
            while (!S.empty() && S.top() != '(') {
                r += S.top(); S.pop();
            }
            S.pop();
        }
    while (!S.empty()) {
        r += S.top(); S.pop();
    }
    cout << r;
    return 0;
}

/*
-로직-
식을 문자열로 입력받으면
스택을 선언하고
문자열 각 문자마다 순회 시작
1. '(' 또는 ')', 연산자가 아닌 문자인 경우 그대로 출력
2. 연산자를 만나면 스택에 저장
3. ')'를 만나면 스택의 top 출력, pop.
순회가 끝나면 스택의 나머지 부분 모두 출력
TC: (A+(B*C))-(D/E)
*/