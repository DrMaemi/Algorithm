def solve(depth, N, M, out):
    if depth == M: # 탈출 조건
        print(" ".join(map(str, out)))
        return
    for i in range(len(visited)):
        if not visited[i]:
            visited[i] = True
            out.append(i+1)
            solve(depth+1, N, M, out)
            #visited[i] = False
            out.pop()
if __name__ == "__main__":
    N, M = map(int, input().split())
    visited = [False]*N
    out = []
    solve(0, N, M, out)