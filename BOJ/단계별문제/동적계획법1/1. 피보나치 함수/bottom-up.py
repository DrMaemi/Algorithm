def ready(max_num):
    cache = [[1, 0], [0, 1]]

    for _ in range(2, max_num+1):
        cache.append([i+j for i, j in zip(cache[-1], cache[-2])])

    return cache


T = int(input())
nums = []

for _ in range(T):
    num = int(input())
    nums.append(num)

cache = ready(max(nums))

for n in nums:
    print(' '.join(map(str, cache[n])))
