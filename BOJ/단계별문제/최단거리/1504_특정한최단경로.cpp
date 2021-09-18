#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAX 801
typedef struct pair {
    int v;
    int w;
} p;

int N, E;
vector<p> adj[MAX];
vector<p> pq;
int dist[3][MAX];
int vias[4];

template<class T>
void swap(T& arr, int i, int j) {
    auto temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

p pq_pop() {
    p _min = pq.front();
    int cursor = pq.size();
    swap(pq, 0, cursor---1);
    int parent = 0;
    while (parent <= cursor/2-1) {
        int child = 2*parent+1;
        if (child+1 < cursor && pq[child+1].w < pq[child].w) {
            child++;
        }
        if (pq[child].w < pq[parent].w) {
            swap(pq, parent, child);
            parent = child;
        }
        else break;
    }
    pq.pop_back();
    return _min;
}

void pq_insert(p input) {
    pq.push_back(input);
    int child = pq.size()-1;
    while (child) {
        int parent = (child-1)/2;
        if (pq[child].w < pq[parent].w) {
            swap(pq, parent, child);
            child = parent;
        }
        else break;
    }
}

void dijkstra(int order) {
    while (!pq.empty()) {
        p _min = pq_pop();
        int next = _min.v;
        for (int e=0; e<adj[next].size(); e++) {
            int dest = adj[next][e].v;
            int cost = adj[next][e].w;
            int previous = dist[order][dest];
            int updated = dist[order][next]+cost;
            if (updated < previous) {
                dist[order][dest] = updated;
                pq_insert({dest, updated});
            }
        }
    }
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> E;
    int u, v, w;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vias[0] = 1; cin >> vias[1] >> vias[2]; vias[3] = N;
    fill(dist[0]+1, dist[0]+N+1, INT_MAX);
    dist[0][vias[0]] = 0;
    pq.push_back({vias[0], 0});
    dijkstra(0);
    int answers[2] = { dist[0][vias[1]], dist[0][vias[2]] };
    for (int i=0; i<2; i++) {
        if (answers[i] == INT_MAX) continue;
        for (int order=1; order<3; order++) {
            fill(dist[order]+1, dist[order]+N+1, INT_MAX);
            dist[order][vias[order]] = 0;
            pq.push_back({vias[order], 0});
            dijkstra(order);
            if (dist[order][vias[order+1]] == INT_MAX) {
                answers[i] = INT_MAX;
                break;
            }
            answers[i] += dist[order][vias[order+1]];
        }
        swap(vias, 1, 2);
    }
    if (answers[0] == INT_MAX && answers[1] == INT_MAX)
        cout << -1;
    else
        cout << (answers[0] < answers[1] ? answers[0] : answers[1]);
    return 0;
}