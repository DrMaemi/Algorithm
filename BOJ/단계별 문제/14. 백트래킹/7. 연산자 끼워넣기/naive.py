import sys

input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
cnts = list(map(int, input().split()))

minv = 1e9
maxv = -1e9

def f(d, v):
    global N, nums, cnts, minv, maxv

    if d == N:
        maxv = max(maxv, v)
        minv = min(minv, v)
        return
    
    for i in range(4):
        if cnts[i]:
            cnts[i] -= 1
            if i == 0: f(d+1, v+nums[d])
            elif i == 1: f(d+1, v-nums[d])
            elif i == 2: f(d+1, v*nums[d])
            else: f(d+1, int(v/nums[d]))
            cnts[i] += 1

f(1, nums[0])
print(maxv)
print(minv)