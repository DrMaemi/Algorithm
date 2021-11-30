T = int(input())
ans = T

for _ in range(T):
    word = input()
    appeared = set()
    p = ''

    for i, x in enumerate(word):
        if x not in appeared:
            appeared.add(x)

        elif x != p:
            ans -= 1
            break

        p = x

print(ans)