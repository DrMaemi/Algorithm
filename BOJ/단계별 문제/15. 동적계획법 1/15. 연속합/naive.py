N = int(input())
A = list(map(int, input().split()))

DP = [0]*N

DP[0] = A[0]

for i in range(1, N):
    DP[i] = max(DP[i-1]+A[i], A[i])

print(max(DP))