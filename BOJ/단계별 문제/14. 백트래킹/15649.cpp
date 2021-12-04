#include <stdio.h>

char a[16] = "               ";
int n, m, visited[8];

void dfs(int depth);

int main(void) {
    scanf("%d%d", &n, &m);
    m += m;
    a[m] = 0;
    dfs(0);
}

void dfs(int depth) {
    if (depth == m) {
        printf("%s\n", a);
        return;
    }
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            a[depth] = i + '1';
            visited[i] = 1;
            dfs(depth+2);
            visited[i] = 0;
        }
    }
}