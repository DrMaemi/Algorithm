N = int(input())
n = 666
found = 0

while True:
    s = str(n)
    cnt = 0

    for c in s:
        if c == '6':
            cnt += 1

            if cnt == 3:
                found += 1

        else:
            cnt = 0

    if found == N:
        print(s)
        break

    n += 1