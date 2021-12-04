from itertools import combinations_with_replacement as cb

N, M = map(int, input().split())

print('\n'.join(map(' '.join, cb(map(str, range(1, N+1)), M))))