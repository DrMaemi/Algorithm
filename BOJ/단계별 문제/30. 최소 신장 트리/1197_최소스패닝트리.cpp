#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct E { int u, v, w; };

int N, M;
int p[100001];

bool cmp(E& _1, E& _2) {
    return _1.w < _2.w;
}

int P(int x) {
    if (p[x] == x) return x;
    return p[x] = P(p[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i=1; i<=N; i++) p[i] = i;
    vector<E> edges(M);
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), cmp);
    int ans = 0, cnt = 0;
    for (E e: edges) {
        if (P(e.u) != P(e.v)) {
            p[P(e.v)] = P(e.u);
            ans += e.w;
            cnt++;
        }
        if (cnt == M-1) break;
    }
    cout << ans;
    return 0;
}

/*
-로직-
간선들을 입력받고
가중치를 기준으로 오름차순 정렬한다.
크기가 가장 작은 간선부터 차례로 선택하되,
선택한 간선의 u, v가 서로 같은 집합이면 사이클이 생기므로 배제한다.
특정 두 노드가 같은 집합인지 아닌지 판별하기 위해 유니온-파인드를 이용한다.
*/