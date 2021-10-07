# Written by jotos - 29200KB, 64ms

import sys
_=input();T={};V=[0]*101
def D(k):
 while T[k]:
  t=T[k].pop()
  if not V[t]:V[t]=1;D(t)
A={(*map(int,sys.stdin.readline().split()),) for i in range(int(input()))}
for a in A:
 for i in [0,1]:T.setdefault(a[i],[]).append(a[1-i])
try:
 while T[1]:D(T[1].pop())
except:pass
print(sum(V[2:]))