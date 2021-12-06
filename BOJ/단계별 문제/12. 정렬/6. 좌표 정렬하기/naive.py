import sys
input = sys.stdin.readline

N = int(input())
l = []

for _ in range(N):
    x, y = map(int, input().split())
    l.append([x, y])

for x, y in sorted(l, key=lambda x:(x[0], x[1])):
    print(x, y)