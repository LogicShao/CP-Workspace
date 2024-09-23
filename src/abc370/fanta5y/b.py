n = int(input())
a = [0] + [[0] + list(map(int, input().split())) for _ in range(n)]
res = 1
for i in range(1, n + 1):
    res = a[res][i] if res >= i else a[i][res]
print(res)
