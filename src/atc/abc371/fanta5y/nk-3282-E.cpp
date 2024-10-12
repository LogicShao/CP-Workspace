#include <bits/stdc++.h>

#define multi_test 0

using LL = long long;

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
    if (p.tag) {
      pl.tag = p.tag;
      pl.sum = (2LL * pl.tag + pl.len() - 1) * pl.len() / 2; // 等差数列求和

      pr.tag = p.tag + pl.len();
      pr.sum = (2LL * pr.tag + pr.len() - 1) * pr.len() / 2;

      p.tag = 0;
    }
  }

  void build(int u, int l, int r, std::vector<int> &a) {
    p = {l, r, 0, 0};
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
  int n, m;
  std::cin >> n >> m;
  
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  SegmentTree tr(n);
  tr.build(1, 1, n, a);

  while (m --) {
    int opt, l, r;
    std::cin >> opt >> l >> r;

    if (opt == 1) {
      int k;
      std::cin >> k;

      tr.modify(1, l, r, k);
    } else {
      std::cout << tr.query(1, l, r) << '\n';
    }
  }
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