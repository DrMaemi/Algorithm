# DrMaemi - 33812KB, 116ms
import sys
input = sys.stdin.readline

N = int(input())
words = []

for _ in range(N):
    words.append(input().strip())

words = list(set(words))

for word in sorted(words, key=lambda x:(len(x), x)):
    print(word)