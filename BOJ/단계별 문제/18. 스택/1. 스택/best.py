# Written by numna - 29452KB, 60ms

import sys

stack = list()

command = dict(
    push=lambda x: stack.append(x),
    pop=lambda: stack.pop() if stack else -1,
    size=lambda: len(stack),
    empty=lambda: 0 if stack else 1,
    top=lambda: stack[-1] if stack else -1
    )

in_data = sys.stdin.readlines()
for c in in_data[1:]:
    c = c.strip()
    if c[:2] == 'pu':
        command['push'](c.split()[1])
    else:
        print(command[c]())