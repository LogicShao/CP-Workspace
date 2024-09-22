#include <bits/stdc++.h>

#define multi_test 0

using LL = long long;

constexpr LL INF = 1e18;

struct node {
  int l, r;
  LL sum; // 维护区间和
  LL tag; // 懒标记维护等差数列的第一个数

  int len() const { return r - l + 1; }
};

struct SegmentTree {
#define ls (u << 1)
#define rs (u << 1 | 1)
#define p tr[u]
#define pl tr[ls]
#define pr tr[rs]
  std::vector<node> tr;

  SegmentTree(int n) : tr(n * 4 + 10) {}

  void push_up(int u) { p.sum = pl.sum + pr.sum; }

  void push_down(int u) {
    if (p.tag != INF) {
      pl.tag = p.tag;
      pl.sum = (2LL * pl.tag + pl.len() - 1) * pl.len() / 2; // 等差数列求和

      pr.tag = p.tag + pl.len();
      pr.sum = (2LL * pr.tag + pr.len() - 1) * pr.len() / 2;

      p.tag = INF;
    }
  }

  void build(int u, int l, int r, std::vector<int> &a) {
    p = {l, r, 0, INF};
    if (l == r) {
      p.sum = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid, a);
    build(rs, mid + 1, r, a);
    push_up(u);
  }

  void modify(int u, int l, int r, int k) {
    if (l <= p.l && p.r <= r) {
      p.tag = k + p.l - l;
      p.sum = (2LL * p.tag + p.len() - 1) * p.len() / 2;
      return;
    }
    push_down(u);
    int mid = (p.l + p.r) >> 1;
    if (l <= mid) {
      modify(ls, l, r, k);
    }
    if (r > mid) {
      modify(rs, l, r, k);
    }
    push_up(u);
  }

  LL query(int u, int l, int r) {
    if (l <= p.l && p.r <= r) {
      return p.sum;
    }
    push_down(u);
    int mid = (p.l + p.r) >> 1;
    LL res = 0;
    if (l <= mid) {
      res += query(ls, l, r);
    }
    if (r > mid) {
      res += query(rs, l, r);
    }
    return res;
  }
#undef pr
#undef pl
#undef p
#undef rs
#undef ls
};

void solve() {
  int n, Q;
  std::cin >> n;

  std::vector<int> a(n + 1);

  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  SegmentTree tr(n);
  tr.build(1, 1, n, a);

  LL ans = 0;
  std::cin >> Q;

  while (Q--) {
    int T, G;
    std::cin >> T >> G;

    if (tr.query(1, T, T) >= G) {
      // 如果 T 位置的值大于等于 G
      // 那么我需要把 [G, X_t] 都移动到 G 位置左边
      int l = 1, r = T;
      while (l < r) {
        int mid = (l + r) >> 1;
        // 二分答案找到左端点
        // check 检查 mid 是否在区间中
        // ID:  [mid, T]: len = T - mid + 1 表示下标的范围
        // Pos: [G - len + 1, G]            表示移动后的位置
        int len = T - mid + 1;
        int L = G - len + 1, R = G;
        if (tr.query(1, mid, mid) >= L) { // 如果 mid 在区间中 说明 mid 需要移动
          r = mid;
        } else {
          l = mid + 1;
        }
      }

      // len is length of [l, T]
      // cost=sum(Pos)-(G + G-1 + ... + G-len+1)
      // cost=sum(Pos)-(G + G - len + 1) * len / 2
      int len = T - l + 1;
      LL cost = tr.query(1, l, T) - ((LL)G * 2 - len + 1) * len / 2;
      ans += cost;

      // 将 [l, T] 移动到 G 位置
      // 也就是把 [l, T] 的左端点设为 G - len + 1
      tr.modify(1, l, T, G - len + 1);
    } else {
      // 如果 T 位置的值小于 G
      // 那么我需要把 [X_t, G] 都移动到 G 位置右边
      int l = T, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        // 二分答案找到右端点
        // check 检查 mid 是否在区间中
        // ID:  [T, mid]: len = mid - T + 1 表示下标的范围
        // Pos: [G, G + len - 1]            表示移动后的位置
        int len = mid - T + 1;
        int L = G, R = G + len - 1; // 表示移动后的位置
        if (tr.query(1, mid, mid) <= R) { // 如果 mid 在区间中 说明 mid 需要移动
          l = mid;
        } else {
          r = mid - 1;
        }
      }

      // len is length of [T, r]
      // cost=(G + G + 1 + ... + G + len - 1)-sum(Pos)
      // cost=(G + G + len - 1) * len / 2 - sum(Pos)
      int len = r - T + 1;
      LL cost = ((LL)G * 2 + len - 1) * len / 2 - tr.query(1, T, r);
      ans += cost;

      // 将 [T, r] 移动到 G 位置
      // 也就是把 [T, r] 的左端点设为 G
      tr.modify(1, T, r, G);
    }
  }

  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}