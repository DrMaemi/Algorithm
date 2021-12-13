import sys

input = sys.stdin.readline

N = int(input())
m = [list(map(int, input().split())) for _ in range(N)]
s, l = [], []
ssum = lsum = 0
ans = 1e9

def f(d, ssum, lsum):
    global ans

    if d == N:
        ans = min(ans, abs(ssum-lsum))
        return

    if len(s) != N/2:
        psum = sum([m[d][i]+m[i][d] for i in s])
        s.append(d)
        f(d+1, ssum+psum, lsum)
        s.pop()

    if len(l) != N/2:
        psum = sum([m[d][i]+m[i][d] for i in l])
        l.append(d)
        f(d+1, ssum, lsum+psum)
        l.pop()

f(0, 0, 0)
print(ans)