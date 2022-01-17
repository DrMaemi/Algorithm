for _ in range(int(input())):
    s = input()
    buff = []
    valid = 1

    for x in s:
        if x == ')':
            if not len(buff) or buff.pop() != '(':
                valid = 0
                break
        
        else: buff.append(x)

    print('YES') if valid and not len(buff) else print('NO')