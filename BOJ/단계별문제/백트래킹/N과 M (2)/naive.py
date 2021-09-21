N, M = map(int, input().split())
q = []

def f(d, p):
    global N, M, q

    if d == M:
        print(' '.join(map(str, q)))
        return
    
    for i in range(p, N):
        q.append(i+1)
        f(d+1, i+1)
        q.pop()


f(0, 0)
