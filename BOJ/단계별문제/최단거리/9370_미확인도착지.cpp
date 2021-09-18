#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define INF INT_MAX
typedef struct pair {
    int v, w;
} P;

int T, n, m, t, s; int via[3];
vector<P> pq;
vector<vector<P>> adj;
int dest[100];
int dist[3][2001];
vector<int> answer;

void swap(int i, int j) {
    P temp = pq[i];
    pq[i] = pq[j];
    pq[j] = temp;
}

P pq_pop() {
    P p = pq.front();
    int size = pq.size();
    swap(0, size---1);
    int parent = 0;
    while (parent <= size/2-1) {
        int child = 2*parent+1;
        if (child+1 < size && pq[child+1].w < pq[child].w)
            child++;
        if (pq[child].w < pq[parent].w) {
            swap(parent, child);
            parent = child;
        }
        else break;
    }
    pq.pop_back();
    return p;
}

void pq_insert(P p) {
    pq.push_back(p);
    int child = pq.size()-1;
    while (child) {
        int parent = (child-1)/2;
        if (pq[child].w < pq[parent].w) {
            swap(parent, child);
            child = parent;
        }
        else break;
    }
}

void dijkstra(int idx) {
    while (!pq.empty()) {
        P p = pq_pop();
        for (int i=0; i<adj[p.v].size(); i++) {
            int v = adj[p.v][i].v;
            int w = adj[p.v][i].w;
            int pre = dist[idx][v];
            int upt = dist[idx][p.v]+w;
            if (upt < pre) {
                dist[idx][v] = upt;
                pq_insert({v, upt});
            }
        }
    }
}

void print_answer() {
    cout << answer[0] << " ";
    for (int i=1; i<answer.size(); i++) {
        if (answer[i-1] == answer[i]) continue;
        cout << answer[i] << " ";
    }
    cout << "\n";
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> m >> t;
        cin >> via[0] >> via[1] >> via[2];
        adj.clear(); adj.resize(n+1);
        int p, q, w;
        while (m--) {
            cin >> p >> q >> w;
            adj[p].push_back({q, w});
            adj[q].push_back({p, w});
        }
        for (int i=0; i<t; i++) cin >> dest[i];
        answer.clear();
        for (int i=0; i<3; i++) {
            fill(dist[i]+1, dist[i]+n+1, INF);
            pq.push_back({via[i], 0}); dist[i][via[i]] = 0;
            dijkstra(i);
        }
        for (int i=0; i<t; i++) {
            if (dist[0][via[1]] != INF && dist[2][dest[i]] != INF
                && dist[0][dest[i]] == dist[0][via[1]]+dist[1][via[2]]+dist[2][dest[i]])
                answer.push_back(dest[i]);
            else if (dist[0][via[2]] != INF && dist[1][dest[i]] != INF
                && dist[0][dest[i]] == dist[0][via[2]]+dist[2][via[1]]+dist[1][dest[i]])
                answer.push_back(dest[i]);
        }
        sort(answer.begin(), answer.end());
        print_answer();
    }
    return 0;
}