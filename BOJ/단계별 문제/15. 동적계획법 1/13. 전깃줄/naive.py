N = int(input())
l = [list(map(int, input().split())) for _ in range(N)]
DP = [1]*N

l.sort(key=lambda x: x[0])

for i in range(1, N):
    for j in range(i-1, -1, -1):
        if l[j][1] < l[i][1]:
            DP[i] = max(DP[i], DP[j]+1)

print(N-max(DP))