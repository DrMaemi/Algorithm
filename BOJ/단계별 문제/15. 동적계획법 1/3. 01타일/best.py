# Written by lsh0426 - 29380KB, 60ms

mem={0:0,1:1}
mod=15746
def tile(t):
    if t in mem:
        return mem[t]
    else:
        if t%2==0:
            a=tile(t//2-1)%mod
            b=tile(t//2)%mod
            f=((2*a+b)*b)%mod
        else:
            f=(tile((t+1)//2)%mod)**2+(tile((t-1)//2)%mod)**2
        mem[t]=f%mod
        return f%mod
print(tile(int(input())+1))