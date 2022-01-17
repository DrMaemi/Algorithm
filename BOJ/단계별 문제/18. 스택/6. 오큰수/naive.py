N = int(input())
v = list(map(int, input().split()))
ans = [-1]*N
s = []

for i in range(N):
    while s and v[s[-1]] < v[i]:
        ans[s[-1]] = v[i]
        s.pop()

    s.append(i)

print(' '.join(map(str, ans)))