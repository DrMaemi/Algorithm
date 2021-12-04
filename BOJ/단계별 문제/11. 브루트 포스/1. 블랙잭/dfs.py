N, M = map(int, input().split())
nums = list(map(int, input().split()))
ans = 0

def f(depth, pos, _sum):
    global N, M, nums, ans

    if depth == 3:
        ans = max(ans, _sum) if _sum <= M else ans
        return

    for i in range(pos, N):
        f(depth+1, i+1, _sum+nums[i])

f(0, 0, 0)
print(ans)
