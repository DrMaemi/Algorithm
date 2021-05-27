from sys import stdin, stdout
input = stdin.readline
print = stdout.write
N = int(stdin.readline())
counts = [0]*10000
for _ in range(N):
    counts[int(input())-1] += 1
for val in range(len(counts)):
    for _ in range(counts[val]):
        print(str(val+1)+'\n')

""" 내 속도 = 8초, 아래 코드 = 3초
f = open(0) 
f.readline()
li=[0]*10001
for line in f:
    li[int(line)] += 1

for i in range(1, 10001):
    print(f'{i}\n' * li[i], end='')
"""