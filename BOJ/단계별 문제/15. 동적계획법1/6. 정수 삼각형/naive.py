# Written by DrMaemi - 38452KB, 216ms

N = int(input())

tr = []
for _ in range(N):
    tr.append(list(map(int, input().split())))

dp = []
for i in range(N):
    dp.append([-1 for _ in range(i+1)])

dp[0][0] = tr[0][0]

for i in range(1, N):
    for j in range(i+1):
        if j == 0:
            dp[i][j] = dp[i-1][j]

        elif j == i:
            dp[i][j] = dp[i-1][j-1]

        else:
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j])

        dp[i][j] += tr[i][j]

print(max(dp[N-1]))