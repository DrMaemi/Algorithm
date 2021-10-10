# Written by DrMaemi - 29200KB, 76ms

N = int(input())

dp = [[1]*10 for _ in range(N+1)]
dp[1][0] = 0

if 1 < N:
    for j in range(2, 9):
        dp[2][j] = dp[1][j-1]+dp[1][j+1]

for i in range(3, N+1):
    dp[i][0] = dp[i-1][1]

    for j in range(1, 9):
        dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1]

    dp[i][9] = dp[i-1][8]

print(sum(dp[N])%1000000000)