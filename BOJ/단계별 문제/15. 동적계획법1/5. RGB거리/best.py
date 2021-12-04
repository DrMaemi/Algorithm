# Writeen by skygarlics - 29056KB, 56ms

import sys
l = sys.stdin.readlines()
d=[];m=min
for _ in l[1:]:d.append(list(map(int,_.split())))
R,G,B=0,0,0
for i in d:R,G,B=m(G,B)+i[0],m(R,B)+i[1],m(R,G)+i[2]
print(m(R,G,B))