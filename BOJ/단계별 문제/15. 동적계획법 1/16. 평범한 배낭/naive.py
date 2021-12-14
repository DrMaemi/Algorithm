N, K = map(int, input().split())

DP = [0]*(K+1)

for _ in range(N):
    W, V = map(int, input().split())

    for used in range(K, W-1, -1):
        DP[used] = max(DP[used], DP[used-W]+V)

print(DP[K])