#include <bits/stdc++.h>

#define multi_test 0

using LL = long long;

constexpr int INF = 0x3f3f3f3f;

struct node {
  int l, r;
  LL sum, tag;

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
      pl.sum += p.tag * pl.len();
      pr.sum += p.tag * pr.len();
      pl.tag += p.tag;
      pr.tag += p.tag;
      p.tag = 0;
    }
  }

  void build(int u, int l, int r, std::vector<int> &a) {
    p.l = l, p.r = r, p.tag = 0;
    if (l == r) {
      p.sum = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid, a);
    build(rs, mid + 1, r, a);
    push_up(u);
  }

  void modify(int u, int l, int r, LL d) {
    if (l <= p.l && p.r <= r) {
      p.sum += d * p.len();
      p.tag += d;
      return;
    }
    push_down(u);
    int mid = (p.l + p.r) >> 1;
    if (l <= mid) {
      modify(ls, l, r, d);
    }
    if (r > mid) {
      modify(rs, l, r, d);
    }
    push_up(u);
  }

  LL query(int u, int x) {
    if (p.l == p.r) {
      return p.sum;
    }
    push_down(u);
    int mid = (p.l + p.r) >> 1;
    if (x <= mid) {
      return query(ls, x);
    } else {
      return query(rs, x);
    }
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

  std::vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  for (int i = n; i >= 2; --i) {
    a[i] -= a[i - 1];
  }

  SegmentTree tr(n);
  tr.build(1, 1, n, a);

  while (m--) {
    int opt;
    std::cin >> opt;

    if (opt == 1) {
      int l, r, k, d;
      std::cin >> l >> r >> k >> d;

      tr.modify(1, l, l, k);
      if (l + 1 <= r) {
        tr.modify(1, l + 1, r, d);
      }
      if (r + 1 <= n) {
        tr.modify(1, r + 1, r + 1, -k - d * (r - l));
      }
    } else {
      int p;
      std::cin >> p;

      std::cout << tr.query(1, 1, p) << '\n';
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