# Written by DrMaemi - 29200KB, 84ms

N, K = map(int, input().split())

l = []

for _ in range(N):
    l.append(int(input()))

ans = 0

for i in reversed(l):
    if i <= K:
        ans += K//i
        K %= i

print(ans)