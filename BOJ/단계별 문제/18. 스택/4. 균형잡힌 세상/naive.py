s = ''

while True:
    s = input()
    stk = []
    ans = 'yes'

    if s == '.':
        break

    for x in s:
        if x == '(' or x == '[':
            stk.append(x)

        elif x == ')':
            if not stk or stk[-1] != '(':
                ans = 'no'
                break

            stk.pop()

        elif x == ']':
            if not stk or stk[-1] != '[':
                ans = 'no'
                break

            stk.pop()

    if stk:
        ans = 'no'

    print(ans)