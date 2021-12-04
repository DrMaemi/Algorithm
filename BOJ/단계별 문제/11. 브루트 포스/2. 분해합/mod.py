# DrMaemi - 29200KB, 1104ms
N = int(input())
ans = 0

for n in range(1, N):
    nn = n
    _sum = n

    while True:
        _sum += nn%10
        nn //= 10

        if not nn:
            break

    if _sum == N:
        ans = n
        break

print(ans)