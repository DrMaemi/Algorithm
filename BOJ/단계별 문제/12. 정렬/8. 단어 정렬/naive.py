# DrMaemi - 32680KB, 124ms
import sys
input = sys.stdin.readline

N = int(input())
words = []

for _ in range(N):
    words.append(input().strip())

words.sort(key=lambda x:(len(x), x))

print(words[0])
for i, word in enumerate(words[1:]):
    if word != words[i]:
        print(word)