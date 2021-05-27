#include <iostream>
using namespace std;
#define MAX 100001

int PO[MAX], IO[MAX], R[MAX];

// s, e는 인 오더 배열의 / s2, e2는 포스트 오더 배열의 시작과 끝 인덱스.
void find_root(int s, int e, int s2, int e2) {
    if (s > e) return;
    // 포스트 오더 배열의 끝이 해당 (서브)트리의 루트 노드이다.
    int r = PO[e2];
    cout << r << " ";
    // 해당 노드가 인 오더 배열의 어느 인덱스(p)에 위치하는지 파악한다.
    int p = R[r];
    // 인 오더 배열에서 p 기준 좌측 배열과 우측 배열로 나누어 재귀.
    // 포스트 오더 배열 시작 인덱스로부터,
    // 인 오더 시작 인덱스와 p와의 차이만큼의 길이를 가지는 구간과
    // 나머지 구간으로 나누어 재귀.
    // 각각 대응하는 인 오더 배열과 포스트 오더 배열은, 포스트 오더 배열의
    // 끝 값이 루트 노드인 서브 트리의 순회와 같음.
    find_root(s, p-1, s2, s2+p-1-s);
    find_root(p+1, e, s2+p-s, e2-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        cin >> IO[i];
        R[IO[i]] = i;
    }
    for (int i=0; i<N; i++)
        cin >> PO[i];
    find_root(0, N-1, 0, N-1);
}