from itertools import combinations as cb

N, M = map(int, input().split())

nums = map(str, [i for i in range(1, N+1)])
results = cb(nums, M)

for r in results:
    print(' '.join(r))