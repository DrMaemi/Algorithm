import sys
input = sys.stdin.readline

N = int(input())
l = []

for _ in range(N):
    age, name = input().split()
    age = int(age)
    l.append([age, name])

for age, name in sorted(l, key=lambda x:x[0]):
    print(age, name)