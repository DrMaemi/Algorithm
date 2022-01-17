import sys

input = sys.stdin.readline

s = []
for _ in range(int(input())):
    n = int(input())
    s.pop() if not n else s.append(n)

print(sum(s))