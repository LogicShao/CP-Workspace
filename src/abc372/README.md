# ABC372

官方题解：https://atcoder.jp/contests/abc372/tasks/abc372_f/editorial

## A

Life is short, You need Python.🥹🥹🥹

```python
print(input().replace('.', ''))
```

## B

贪一下就好。

## C

很板的字符串匹配，求出一开始的 `cnt`，每一次维护修改后 `cnt` 的变化即可。

## D

很板的单调栈，我们只要求出每一个数左边最近的大于这个数的位置 $p$ 即可。显然有一段区间 $+1$ 的操作，直接前缀和维护一下就行。不过这里要注意看题意，每次操作的区间为 $[max(1,p),i)$。

## E

很板的并查集，我们只需要额外维护每一个联通块中最大的 $10$ 个数字即可。由于 $10$ 很小，我们怎么维护都可以。