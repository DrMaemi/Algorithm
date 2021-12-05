import sys
input = sys.stdin.readline

N = int(input())
A = []
cnts = {}

for _ in range(N):
    n = int(input())
    
    A.append(n)
    cnts[n] = cnts[n]+1 if n in cnts else 1

A.sort()
P = [[n, cnt] for n, cnt in cnts.items()]
P.sort(key=lambda x:(-x[1], x[0]))

print(round(sum(A)/len(A)))
print(A[len(A)//2])
print(P[0][0] if len(P) == 1 or P[0][1] != P[1][1] else P[1][0])
print(max(A)-min(A))