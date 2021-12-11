# Written by DrMaemi - 29200KB, 64ms

import sys
input = sys.stdin.readline

def f():
    T = int(input())

    l = [0, 1, 1, 1, 2, 2]
    Ns = []

    for _ in range(T):
        Ns.append(int(input()))

    for i in range(6, max(Ns)+1):
        l.append(l[i-5]+l[i-1])

    for N in Ns:
        print(l[N])

if __name__ == '__main__':
    f()