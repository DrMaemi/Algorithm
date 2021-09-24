# Written by DrMaemi - 29200KB, 72ms
N = int(input())

s = []
l = 0

def f():
    global N, s, l

    if l == N:
        print(''.join(map(str, s)))
        exit(0)

    for i in range(1, 4):
        s.append(i)
        l += 1
        bad = False

        for p in range(1, l//2+1):
            if s[l-2*p:l-p] == s[l-p:]:
                bad = True
                break
        
        if not bad:
            f()
        
        s.pop()
        l -= 1

f()