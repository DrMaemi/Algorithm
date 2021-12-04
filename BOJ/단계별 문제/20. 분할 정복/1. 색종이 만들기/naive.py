# Written by DrMaemi - 29200KB, 92ms

N = int(input())

M = []
for _ in range(N):
    M.append(list(map(int, input().split())))

w = b = 0

def f(i, j, l):
    global w, b

    p = M[i][j]
    for y in range(i, i+l):
        for x in range(j, j+l):
            if M[y][x] != M[i][j]:
                nl = l//2
                f(i, j, nl)
                f(i+nl, j, nl)
                f(i, j+nl, nl)
                f(i+nl, j+nl, nl)
                return

    if p == 0:
        w += 1
    else:
        b += 1

f(0, 0, N)
print(w)
print(b)