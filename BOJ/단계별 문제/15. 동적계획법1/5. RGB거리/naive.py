# Written by DrMaemi - 29452KB, 108ms

N = int(input())

C = []
for _ in range(N):
    C.append(tuple(map(int, input().split())))

M = [[-1, -1, -1] for _ in range(N)]
M[0] = C[0]

for i in range(1, N):
    M[i][0] = min(M[i-1][1], M[i-1][2])+C[i][0]
    M[i][1] = min(M[i-1][0], M[i-1][2])+C[i][1]
    M[i][2] = min(M[i-1][0], M[i-1][1])+C[i][2]

print(min(M[N-1]))