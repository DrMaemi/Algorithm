# Written by DrMaemi - 29200KB, 336ms

N = int(input())
mod = 15746

if N < 4:
    print(N)

else:
    a, b, c = 1, 2, 3
    for _ in range(N-3):
        tmp = (b+c)%mod
        a = b
        b = c
        c = tmp

    print(c)