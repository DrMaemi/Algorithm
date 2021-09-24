# Written by dkvmflzk98 - 29284KB, 52ms
n = int(input())

def bt(d, s):
    if d == n:
        print(s)
        exit(0)
    
    for i in ['1', '2', '3']:
        c = s + i
        bad = False
        for l in range(1, len(c)//2 + 1):
            f, b = c[d+1-2*l:d+1-l], c[d+1-l:]
            if f == b:
                bad = True
                break
        if not bad:
            bt(d+1, s + i)

bt(0, '')