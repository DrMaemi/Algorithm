#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define MAX 101

using namespace std;

bool visit[MAX];
int answer = 0;

void dfs(vector<int>* vec, int start);

int main(void) {
    //ios::sync_with_stdio(false);
    int n, m, node1, node2;
    cin >> n >> m;
    vector<int> adj[n+1];
    for (int i=0; i<m; i++) {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    fill(visit, visit+MAX, false);
    dfs(adj, 1);
    cout << answer-1 << "\n";
}

void dfs(vector<int>* vec, int start) {
    visit[start] = true;
    //cout << start << " ";
    answer++;
    for (auto &&i : vec[start]) {
        if (!visit[i]) { dfs(vec, i); }
    }
}