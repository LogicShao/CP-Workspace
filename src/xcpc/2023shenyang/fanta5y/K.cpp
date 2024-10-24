#include <bits/stdc++.h>

#define multi_test 0
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

struct SegmentTree {
  struct node {
    int l, r;
    LL sum, add;
  };

#define lson (u << 1)
#define rson (u << 1 | 1)
#define p tr[u]
#define pl tr[lson]
#define pr tr[rson]

  std::vector<node> tr;
  SegmentTree(int n) : tr((n + 5) << 2) {}

  void push_up(int u) { p.sum = pl.sum + pr.sum; }

  void push_down(int u) {
    if (p.add) {
      pl.sum += p.add * (pl.r - pl.l + 1);
      pr.sum += p.add * (pr.r - pr.l + 1);
      pl.add += p.add;
      pr.add += p.add;
      p.add = 0;
    }
  }

  void modify(int u, int l, int r, int d) {
    if (p.l >= l and p.r <= r) {
      p.sum += d * (p.r - p.l + 1);
      p.add += d;
      return;
    }
    push_down(u);
    int mid = (p.l + p.r) >> 1;
    if (l <= mid) {
      modify(lson, l, r, d);
    }
    if (r > mid) {
      modify(rson, l, r, d);
    }
    push_up(u);
  }

  LL query(int u, int l, int r) {
    if (p.l >= l and p.r <= r) {
      return p.sum;
    }
    push_down(u);
    int mid = (p.l + p.r) >> 1;
    LL res = 0;
    if (l <= mid) {
      res += query(lson, l, r);
    }
    if (r > mid) {
      res += query(rson, l, r);
    }
    return res;
  }

#undef pr
#undef pl
#undef p
#undef rson
#undef lson
};

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> postive(1), a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    if (a[i] > 0) {
      postive.push_back(i);
    }
  }
  std::vector<PII> change(q);
  for (auto &[x, v] : change) {
    std::cin >> x >> v;
    if (v > 0) {
      postive.push_back(x);
    }
  }
  std::sort(postive.begin() + 1, postive.end());
  postive.erase(std::unique(postive.begin() + 1, postive.end()), postive.end());
  std::map<int, int> rnk;
  for (int i = 1; i < (int)postive.size(); ++i) {
    rnk[postive[i]] = i;
  }
  SegmentTree st(postive.size());
  for (int i = 1; i <= n; ++i) {
    if (a[i] > 0) {
      st.modify(1, rnk[i], rnk[i], a[i]);
    }
  }
  for (auto &[x, v] : change) {
    
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (DEBUG) {
    std::cerr.tie(nullptr)->sync_with_stdio(false);
    freopen("data.in", "r", stdin);
  }

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}