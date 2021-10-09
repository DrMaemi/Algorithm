# Written by DrMaemi - 29200KB, 68ms

import sys
input = sys.stdin.readline

N = int(input())

d0 = d1 = d2 = 0

for _ in range(N):
    v = int(input())
    d0, d1, d2 = max(d1, d2), d0+v, d1+v

print(max(d1, d2))