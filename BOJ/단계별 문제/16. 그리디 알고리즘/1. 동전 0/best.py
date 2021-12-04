# Written by jiyoung1329 - 29284KB, 52ms

N, K = map(int, input().split())

Coins = []
for i in range(N) : Coins.append(int(input()))


ans = 0
while K > 0 :
    coin = Coins.pop()
    ans += K // coin
    K %= coin

print(ans)