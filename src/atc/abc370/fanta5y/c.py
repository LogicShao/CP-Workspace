s = input()
t = input()
res = sum(s[i] != t[i] for i in range(len(s)))
print(res)
for _ in range(res):
    pos = -1
    for i in range(len(s)):
        if s[i] > t[i]:
            pos = i
            break
    if pos != -1:
        s = s[:pos] + t[pos] + s[pos + 1:]
    else:
        for i in range(len(s))[::-1]:
            if s[i] != t[i]:
                pos = i
                break
        s = s[:pos] + t[pos] + s[pos + 1:]
    print(s)