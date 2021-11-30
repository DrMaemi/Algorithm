T = int(input())
ans = 0

for _ in range(T):
    word = input()
    appeared = [0]*(ord('z')-ord('a')+1)
    valid = 1

    p = word[0]
    appeared[ord(p)-ord('a')] = 1

    for x in word[1:]:
        if not appeared[ord(x)-ord('a')]:
            appeared[ord(x)-ord('a')] = 1

        elif x != p:
            valid = 0
            break

        p = x

    if valid:
        ans += 1

print(ans)