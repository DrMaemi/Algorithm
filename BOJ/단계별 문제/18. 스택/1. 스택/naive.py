# Written by DrMaemi - 29200KB, 72ms

import sys
input = sys.stdin.readline

N = int(input())
stack = []

for _ in range(N):
    c = input().split()

    if c[0] == 'push':
        stack.append(c[1])

    elif c[0] == 'pop':
        print(stack.pop()) if stack else print(-1)

    elif c[0] == 'size':
        print(len(stack))

    elif c[0] == 'empty':
        print(0) if stack else print(1)

    elif c[0] == 'top':
        print(stack[-1]) if stack else print(-1)