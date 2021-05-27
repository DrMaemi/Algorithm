def dfs(cnt):
    if cnt == M:
        print(" ".join(map(str, stack)))
        return
    for num in range(1, N+1):
        stack.append(num)
        dfs(cnt+1)
        stack.pop()
N, M = map(int, input().split())
stack = []
dfs(0)