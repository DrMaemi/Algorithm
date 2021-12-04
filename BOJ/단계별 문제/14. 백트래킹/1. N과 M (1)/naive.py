N, M = map(int, input().split())

q = []
visited = [False for _ in range(N+1)]

def f(d):
    global N, M, q

    if d == M:
        print(' '.join(map(str, q)))
        return
    
    for i in range(1, N+1):
        if not visited[i]:
            q.append(i)
            visited[i] = True
            f(d+1)
            visited[i] = False
            q.pop()

f(0)