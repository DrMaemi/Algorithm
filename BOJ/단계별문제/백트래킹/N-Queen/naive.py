# DrMaemi - (PyPy3) 135236KB, 4640ms

N = int(input())

c = [0]*N
d1 = [0]*(2*N-1)
d2 = [0]*(2*N-1)

ans = 0

def f(j):
    global ans

    if j == N:
        ans += 1
        return

    for i in range(N):
        if not (c[i] or d1[i+j] or d2[N-1+i-j]):
            c[i] = d1[i+j] = d2[N-1+i-j] = 1
            f(j+1)
            c[i] = d1[i+j] = d2[N-1+i-j] = 0

f(0)
print(ans)