word = input()
ans = 0

for x in word:
    n = 0
    
    if 'S' <= x:
        n += 1

    if 'Z' <= x:
        n += 1

    ans += (ord(x)-65-n)//3+3

print(ans)