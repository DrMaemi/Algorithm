# Written by wider93 - 29284KB, 64ms

import sys
input = sys.stdin.readline

n = int(input())

paper = [[*map(int, input().split())] for i in range(n)]

def split4(x, y, size1):
    x1 = x + size1
    y1 = y + size1
    yield x, y
    yield x1, y
    yield x, y1
    yield x1, y1

def color(x, y, size):
    if size == 1:
        return (0, 1) if paper[x][y] else (1, 0)
    a, b = 0, 0
    size1 = size // 2
    for u, v in split4(x, y, size1):
        a1, b1 = color(u, v, size1)
        a += a1
        b += b1
    if a == 0:
        return 0, 1
    elif b == 0:
        return 1, 0
    return a, b

a, b = color(0, 0, n)
print(a)
print(b)