import math

m = int(input())
res = []
while m > 0:
    t = int(math.log(m, 3))
    res.append(t)
    m -= 3 ** t
print(len(res))
print(*res)
