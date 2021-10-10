# Written by naurud - 29284KB, 52ms

n = int(input())

DP = [[0]*10 for i in range(101)]
DP[1] = [0,1,1,1,1,1,1,1,1,1]

for i in range(2,n+1):
    for j in range(10):
        if j == 0:
            DP[i][j] = DP[i-1][j+1]
        elif j == 9:
            DP[i][j] = DP[i-1][j-1]
        else:
            DP[i][j] = DP[i-1][j+1] + DP[i-1][j-1]
result = 0
for i in range(0,10):
    result += DP[n][i]

print(result%1000000000)