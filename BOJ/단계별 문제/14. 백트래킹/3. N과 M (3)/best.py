from itertools import product

N, M = map(int,input().split())

nums = list(map(str, range(1, N+1)))

print('\n'.join(list(map(' '.join, product(nums, repeat=M)))))
