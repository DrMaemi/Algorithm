N = int(input())
S = list(map(int, input().split()))
L = [0]*N
R = [0]*N

for i in range(1, N):
    for j in range(i, -1, -1):
        if S[j] < S[i]:
            L[i] = max(L[i], L[j]+1) 

for i in range(N-2, -1, -1):
    for j in range(i+1, N):
        if S[j] < S[i]:
            R[i] = max(R[i], R[j]+1)

print(max([l+r for l, r in zip(L, R)])+1)