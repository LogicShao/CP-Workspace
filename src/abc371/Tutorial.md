# ABC371

[官方题解](https://atcoder.jp/contests/abc371/editorial)
[文字题解](https://www.cnblogs.com/Lanly/p/18414807)
[视频题解](https://www.bilibili.com/video/BV1dF4UeHEHM/)

| 题目 | Hint                                                         |
| :--- | :----------------------------------------------------------- |
| A    | pass                                                         |
| B    | pass                                                         |
| C    | 使用 `std::next_permutation` 遍历全排列                      |
| D    | 排序之后求前缀和，每一次查询二分找到对应的位置               |
| E    | 注意到 $1\le A_i\le N$，那么我们可以发现 $f(i,j)=\sum_{t=1}^{N}{any(A_k=t;i\le k\le j)}$；<br />那么有 $\sum_{i=1}^{N}{\sum_{j=i}^{N}{f(i,j)}}=\sum_{t=1}^{N}{all(t\in A_{l\dots r};1\le l\le r\le N)}$；<br />即每一个数在一个区间中出现了，就会对答案贡献 $1$；<br />那么对于每一个 $t$，我们统计出包含 $t$ 的子区间个数并求和即可。<br />对于每一个 $t$，我们考虑反面即可。 |
| F    |                                                              |
|      |                                                              |

