# Written by wndlswo12 - 29056KB, 64ms

from sys import stdin
n = int(input());t=[int(stdin.readline()) for _ in range(n)];a,b,c = 0,0,0
for i in t:a,b,c = max(a,b,c),a+i,b+i
print(max(a,b,c))