b = [[0]*9 for _ in range(9)]
r = [[0]*10 for _ in range(9)]
c = [[0]*10 for _ in range(9)]
p = [[[0]*10 for _ in range(3)] for _ in range(3)]
v = []
found = 0
max_depth = 0

def f(d):
    global b, r, c, p, v, found, max_depth

    if (d == max_depth):
        for i in range(9):
            for j in range(9):
                print(b[i][j], end=' ')

            print()

        found = 1
        return

    i, j = v[d]
    for n in range(1, 10):
        if not (r[i][n] or c[j][n] or p[i//3][j//3][n]):
            b[i][j] = n
            r[i][n] = c[j][n] = p[i//3][j//3][n] = 1
            f(d+1)
            r[i][n] = c[j][n] = p[i//3][j//3][n] = 0

        if found: break

if __name__ == '__main__':
    for i in range(9):
        for j, n in enumerate(map(int, input().split())):
            b[i][j] = n

            if n:
                r[i][n] = c[j][n] = p[i//3][j//3][n] = 1

            else:
                v.append((i, j))
                max_depth += 1

    f(0)