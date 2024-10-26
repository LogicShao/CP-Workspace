#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

struct SegmentTree {
  struct node {
    int l, r;
    LL sum, set_tag;
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
    if (p.set_tag != -1) {
      pl.sum = p.set_tag * (pl.r - pl.l + 1);
      pr.sum = p.set_tag * (pr.r - pr.l + 1);
      pl.set_tag = pr.set_tag = p.set_tag;
      p.set_tag = -1;
    }
  }

  void build(int u, int l, int r, const std::vector<int> &a) {
    p.l = l, p.r = r, p.set_tag = -1;
    if (l == r) {
      p.sum = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid, a);
    build(rson, mid + 1, r, a);
    push_up(u);
  }

  void modify(int u, int l, int r, LL v) {
    if (l <= p.l and p.r <= r) {
      p.sum = v * (p.r - p.l + 1);
      p.set_tag = v;
      return;
    }
    push_down(u);
    int mid = (p.l + p.r) >> 1;
    if (l <= mid) {
      modify(lson, l, r, v);
    }
    if (r > mid) {
      modify(rson, l, r, v);
    }
    push_up(u);
  }

  LL query(int u, int l, int r) {
    if (l <= p.l and p.r <= r) {
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
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<PII> station(m + 1);
  std::vector<bool> has_station(n + 1);
  for (int i = 1; i <= m; ++i) {
    std::cin >> station[i].first >> station[i].second;
    has_station[station[i].second] = true;
  }

  LL rest = 0;
  for (int i = 1; i <= n; ++i) {
    if (!has_station[i]) {
      rest += a[i];
      a[i] = 0;
    }
  }

  std::vector<int> charge_order(m + 1);
  std::vector<std::queue<int>> q(n + 1);

  for (int i = 1; i <= m; ++i) {
    int kind = station[i].second;
    if (q[kind].empty()) {
      charge_order[i] = a[kind];
    }
    q[kind].push(i);
  }

  SegmentTree st(m);
  st.build(1, 1, m, charge_order);

  LL dist = 0;
  for (int i = 1; i <= m; ++i) {
    auto [pos, kind] = station[i];
    if (dist + st.query(1, i, m) < pos) {
      dist += st.query(1, i, m);
      st.modify(1, i, m, 0);
      if (dist + rest < pos) {
        break;
      } else {
        rest -= pos - dist;
        dist = pos;
      }
    } else if (dist + st.query(1, i, i) >= pos) {
      auto v = st.query(1, i, i);
      st.modify(1, i, i, v - (pos - dist));
      dist = pos;
    } else {
      int l = i, r = m;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (dist + st.query(1, i, mid) >= pos) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      l--;
      dist += st.query(1, i, l);
      st.modify(1, i, l, 0);
      auto v = st.query(1, l + 1, l + 1);
      st.modify(1, l + 1, l + 1, v - (pos - dist));
      dist = pos;
    }

    q[kind].pop();
    if (q[kind].size()) {
      int idx = q[kind].front();
      st.modify(1, idx, idx, a[kind]);
    } else {
      rest += a[kind];
    }
  }

  dist += rest;

  std::cout << dist << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (DEBUG) {
    std::cerr.tie(nullptr);
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