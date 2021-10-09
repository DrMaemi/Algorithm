# Written by wndlswo12 - 29284KB, 52ms

from sys import stdin

a,b,c = 0,0,0

n = int(stdin.readline())
for _ in range(n):
    pb = int(stdin.readline())
    d_0,d_1,d_2 = max(b,c),a+pb,b+pb
    a,b,c = d_0,d_1,d_2

print(max(d_2,d_1))