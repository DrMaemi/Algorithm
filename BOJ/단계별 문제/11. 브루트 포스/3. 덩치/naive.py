N = int(input())

whs = []

for _ in range(N):
    w, h = map(int, input().split())
    whs.append((w, h))

rs = []

for i, (p, q) in enumerate(whs):
    r = 1

    for j, (x, y) in enumerate(whs):
        if i != j and x > p and y > q:
            r += 1
            
    rs.append(r)

print(' '.join(map(str, rs)))
