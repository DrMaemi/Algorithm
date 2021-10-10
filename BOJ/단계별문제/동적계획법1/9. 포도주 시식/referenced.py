# Written by DrMaemi - 29452KB, 72ms

import sys
input = sys.stdin.readline

N = int(input())

l = [int(input()) for _ in range(N)]
d0 = d1 = d2 = 0

for v in l:
    d0, d1, d2 = max(d0, d1, d2), d0+v, d1+v

print(max(d0, d1, d2))