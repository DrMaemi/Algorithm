from itertools import combinations_with_replacement as cb

N, M = map(int, input().split())

for c in cb(range(1, N+1), M):
    print(' '.join(map(str, c)))
