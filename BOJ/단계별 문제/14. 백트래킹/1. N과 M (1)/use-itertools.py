import itertools as it

N, M = map(int, input().split())

nums = [i for i in range(1, N+1)]

permutations = it.permutations(nums, M)

for permutation in permutations:
    print(' '.join(map(str, permutation)))