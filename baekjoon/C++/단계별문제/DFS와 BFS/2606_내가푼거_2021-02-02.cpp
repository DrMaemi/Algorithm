#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101

int N, M, answer;
vector<int> adj[MAX];
bool visited[MAX] = { false, };

void Input() {
    cin >> N >> M;
    int node1, node2;
    for (int i=0; i<M; i++) {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
}

void SortVec(vector<int>* V, int size) {
    for (int i=0; i<size; i++) {
        sort(V[i].begin(), V[i].end());
    }
}

void dfs(int node){
    visited[node] = true;
    answer++;
    for (int i=0; i<adj[node].size(); i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main(void) {
    Input();
    //SortVec(adj, N);
    dfs(1);
    cout << --answer;
    return 0;
}