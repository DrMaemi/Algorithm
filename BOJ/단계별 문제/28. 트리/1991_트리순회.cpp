#include <iostream>
#include <vector>
using namespace std;
#define V vector
#define c char

int N;
V<V<int>> adj;

void preorder(int n) {
    cout << (c)('A'+n);
    for (int nx: adj[n])
        if (nx != -1)
            preorder(nx);
}

void inorder(int n) {
    if (adj[n][0] != -1)
        inorder(adj[n][0]);
    cout << (c)('A'+n);
    if (adj[n][1] != -1)
        inorder(adj[n][1]);
}

void postorder(int n) {
    for (int nx: adj[n])
        if (nx != -1)
            postorder(nx);
    cout << (c)('A'+n);
}

void print_adj() {
    cout << "print_adj():\n";
    for (int i=0; i<adj.size(); i++) {
        cout << (c)(i+'A') << " ";
        for (int j=0; j<2; j++)
            cout << (c)(adj[i][j]+'A') << " ";
        cout << "\n";
    }
}

int main() {
    cin >> N;
    adj.resize(N);
    for (int i=0; i<N; i++)
        adj[i].resize(2, -1);
    while (N--) {
        char v[3];
        for (int j=0; j<3; j++)
            cin >> v[j];
        for (int j=1; j<3; j++)
            if (v[j] != '.')
                adj[v[0]-'A'][j-1] = v[j]-'A';
    }
    print_adj();
    preorder(0); cout << "\n";
    inorder(0); cout << "\n";
    postorder(0);
    return 0;
}