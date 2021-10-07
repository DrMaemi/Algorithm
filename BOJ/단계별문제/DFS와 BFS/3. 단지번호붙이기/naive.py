# Written by DrMaemi - 34268, 120ms

from queue import Queue

N = int(input())

map = []
for _ in range(N):
    r = input()
    _r = []
    for c in r:
        _r.append(int(c))
    map.append(_r)

visited = [[False]*N for _ in range(N)]

q = Queue()
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
ans = []

for y in range(N):
    for x in range(N):
        if map[y][x] == 1 and not visited[y][x]:
            q.put((y, x))
            visited[y][x] = True
            cnt = 0

            while not q.empty():
                fy, fx = q.get()
                cnt += 1
                
                for i in range(4):
                    ny, nx = fy+dy[i], fx+dx[i]
                    if ny >= 0 and nx >= 0 and ny < N and nx < N \
                            and map[ny][nx] == 1 and not visited[ny][nx]:
                        q.put((ny, nx))
                        visited[ny][nx] = True

            ans.append(cnt)

print(len(ans))
for cnt in sorted(ans):
    print(cnt)