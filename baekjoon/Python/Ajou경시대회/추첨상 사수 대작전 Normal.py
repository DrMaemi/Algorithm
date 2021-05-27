import sys
input = sys.stdin.readline
print = sys.stdout.write
m, seed, x1, x2 = map(int, input().split())
for a in range(0, m+1):
    if (a*(seed-x1)-x1+x2)%m == 0:
        for c in range(0, m+1):
            if (a*x1+c)%m == x2:
                print("{} {}".format(a, c))
                sys.exit(0)