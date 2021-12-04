# DrMaemi - 29200KB, 1372ms
N = int(input())
ans = 0

for n in range(1, N):
    _sum = n+sum(list(map(int, str(n))))

    if _sum == N:
        ans = n
        break

print(ans)