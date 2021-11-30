# DrMaemi - 31156KB, 112ms
cnts = []

word = input().upper()
appeared = list(set(word))

for x in appeared:
    cnts.append(word.count(x))

max_cnt = max(cnts)

if 1 < cnts.count(max_cnt):
    print('?')

else:
    print(appeared[cnts.index(max_cnt)])