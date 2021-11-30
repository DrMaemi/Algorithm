# DrMaemi - 29200KB, 68ms
s = input()

atoz = list(range(97, 123))

for c in atoz:
    print(s.find(chr(c)), end=' ')