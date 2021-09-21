from itertools import product

N, M = map(int, input().split())

nums = [i for i in range(1, N+1)]

results = product(nums, repeat=M)

for r in results:
    print(' '.join(map(str, r)))
