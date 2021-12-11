# Written by experien - 29288KB, 52ms

from sys import stdin

P = [0, 1, 1, 1, 2, 2, 3]
for n in range(7, 101):
    P.append(P[n-1] + P[n-5])

next(stdin)
for n in map(int, stdin):
    print(P[n])