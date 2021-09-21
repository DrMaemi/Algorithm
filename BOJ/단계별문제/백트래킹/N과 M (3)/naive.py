N, M = map(int, input().split())
q = []

def f(d):
    global N, M

    if d == M:
        print(' '.join(map(str, q)))
        return
    
    for i in range(1, N+1):
        q.append(i)
        f(d+1)
        q.pop()


f(0)
