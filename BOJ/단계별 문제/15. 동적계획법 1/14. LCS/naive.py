a = ' '+input()
b = ' '+input()

DP = [[0]*len(b) for _ in range(len(a))]

for i in range(1, len(a)):
    for j in range(1, len(b)):
        if a[i] == b[j]:
            DP[i][j] = DP[i-1][j-1]+1

        else:
            DP[i][j] = max(DP[i-1][j], DP[i][j-1])

print(DP[len(a)-1][len(b)-1])