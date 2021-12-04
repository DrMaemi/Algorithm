# Written by whdgurclzls - 29056KB, 56ms

from sys import*
input = stdin.readline

def lower(l, r, x):
    while l <= r:
        m = (l+r)//2
        if v[m] >= x:
            r = m-1
        else:
            l = m+1
    return l

n = int(input())
arr = list(map(int,input().split()))
v = [arr[0]]

for i in range(1,n):
    if v[-1] < arr[i]:
        v.append(arr[i])
    else:
        v[lower(0, len(v)-1, arr[i])] = arr[i]

print(len(v))