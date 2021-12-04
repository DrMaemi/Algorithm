# DrMaemi - 35700KB, 616ms
from queue import Queue

def dfs(u):
    global visited
    visited[u] = True
    print(f'{u} ', end='')

    for v in adj[u]:
        if not visited[v]:
            dfs(v)

def bfs(u):
    global visited
    q = Queue()
    q.put(u)
    visited[u] = True

    while not q.empty():
        f = q.get()
        print(f'{f} ', end='')
        for v in adj[f]:
            if not visited[v]:
                q.put(v)
                visited[v] = True


if __name__ == '__main__':
    N, M, V = map(int, input().split())
    adj = {u: [] for u in range(1, N+1)}

    for _ in range(M):
        u, v = map(int, input().split())
        
        adj[u].append(v)
        adj[v].append(u)

    for v in adj.values():
        v.sort()

    visited = {u: False for u in range(1, N+1)}
    dfs(V)
    print()
    
    visited = {u: False for u in range(1, N+1)}
    bfs(V)
