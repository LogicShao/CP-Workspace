def solve(n):
    l = 10 ** (n - 1)
    low = (l + 65) // 66 * 66
    for i in range(low, 10 ** n, 66):
        sti = set(str(i))
        st0 = set('36')
        if sti | st0 == st0:
            return i
    return -1


for i in range(1, 10):
    print(i, solve(i))
