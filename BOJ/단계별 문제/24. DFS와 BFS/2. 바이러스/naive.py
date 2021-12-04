# Written by DrMaemi - 29200KB, 72ms

V = int(input())
E = int(input())

adj = [[] for _ in range(V+1)]

for _ in range(E):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

visited = [False for _ in range(V+1)]
cnt = 0

def dfs(u):
    global visited, cnt

    if visited[u]:
        return
        
    visited[u] = True
    cnt += 1

    for v in adj[u]:
        dfs(v)

dfs(1)
print(cnt-1)