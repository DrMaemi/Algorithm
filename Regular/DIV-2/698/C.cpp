#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<ll> d(2*n), a; bool f = 1;
        for (int i=0; i<2*n; i++) cin >> d[i];
        sort(d.begin(), d.end(), greater<ll>());
        for (int i=0; i<2*n; i+=2)
            if (d[i] != d[i+1]) { f = 0; break; }
        if (!f) { cout << "NO\n"; continue; }
        d.erase(unique(d.begin(), d.end()), d.end());
        if (d.size() != n) { cout << "NO\n"; continue; }
        for (int di: d) if (di%2) { f = 0; break; }
        if (!f) { cout << "NO\n"; continue; }
        ll ps = 0;
        for (int i=0; i<n; i++) {
            if ((d[i]-2*ps)%(2*(n-i)) || d[i] <= 2*ps) {
                f = 0; break;
            }
            a.push_back((d[i]-2*ps)/(2*(n-i)));
            ps += a.back();
        }
        if (f && a.size() == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
-로직-
n = 4인 경우
d1 = abs(a1-a1) + ... + abs(a1-a4) + abs(a1+a1) + ... + abs(a1+a4)
이 때, a1이 가장 큰 수라고 가정해보자.
그러면 abs 연산을 무시할 수 있으므로
d1 = 8*a1

마찬가지로, a2가 두 번째로 가장 큰 수라면
d2 = abs(a2-a1) + ... + abs(a2-a4) + abs(a2+a1) + ... + abs(a2+a4)
   = a1-a2 + a2+a1 + 6*a2
   = 2*a1 + 6*a2

d3 = abs(a3-a1) + ... + abs(a3-a4) + abs(a3+a1) + ... + abs(a3-a4)
   = a1-a3 + a2-a3 + a3+a1 + a3+a2 + 4*a3
   = 2*a1 + 2*a2 + 4*a3

...

di = 2*(a1+...+a(i-1)) + 2*(n-i+1)*ai


위 식을 보면, 다음과 같은 성질을 가짐을 알 수 있다.
1. 입력한 d를 내림차순으로 정렬했을 때 가장 큰 것부터 d1, ..., d(2n)이 된다.
2. d 배열에 존재하는 서로 다른 수는 각각 반드시 두 개씩 존재한다.
3. 모든 di에 대해 2로 나눌 수 있으므로 짝수임을 알 수 있다.
또한, 위 식을 통해 a1, a2, ..., an은 각각 a(2n), a(2n-1), ..., a1과 같음을
증명할 수 있다(a가 symmetric array이기 때문에 이와 같은 성질을 만족).
각 식을 a에 관하여 다시 정리하면,
a1 = d1/(2*n)
a2 = (d2-2*a1)/(2*(n-1))
a3 = (d3-2*(a1+a2))/(2*(n-2))
...
ai = (di-2*(a1+...+a(i-1)))/(2*(n-i+1))

먼저 1, 2, 3에 대한 검사를 진행한 후
i를 1부터, 2n이 아닌 n까지 순회할 때 위 등식이 만족되는지 검사한다.
검사 방법은, 각 등식의 우변 분자를 분모로 나머지 연산을 수행했을 때
나머지가 0이면 만족한다고 판단한다.
한 편, a1 ~ an은 모두 양의 정수이므로 등식 우변 분자가 0 초과이어야 한다.
2n까지 등식을 모두 만족한다면 YES, 아니라면 NO를 출력한다.
*/