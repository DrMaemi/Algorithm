def dfs(cnt):
    if cnt == M:
        print(" ".join(map(str, stack)))
        return
    if len(stack) == 0: start = 1
    else: start = stack[-1]
    for num in range(start, N+1):
        stack.append(num)
        dfs(cnt+1)
        stack.pop()
N, M = map(int, input().split())
stack = []
dfs(0)