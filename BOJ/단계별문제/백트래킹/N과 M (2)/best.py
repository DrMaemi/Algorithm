n, m = map(int, input().split())

def f(v, nn, mm):
    if mm >= m:
        print(v[:len(v)-1])
        return
    
    for i in range(nn,n+1):
        if v.count(str(i))==0:
            mm += 1
            t = v+str(i)+' '
            f(t,i,mm)
            mm -= 1

f('', 1, 0)