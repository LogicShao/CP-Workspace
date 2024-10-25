#include <bits/stdc++.h>

#define multi_test 0
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

struct SegmentTree {
  struct node {
    int l, r, cnt;
    LL sum;
  };

#define lson (u << 1)
#define rson (u << 1 | 1)
#define p tr[u]
#define pl tr[lson]
#define pr tr[rson]

  std::vector<node> tr;
  SegmentTree(int n) : tr((n + 5) << 2) { build(1, 1, n); }

  void build(int u, int l, int r) {
    p.l = l, p.r = r;
    p.sum = p.cnt = 0;
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
  }

  void push_up(int u) {
    p.sum = pl.sum + pr.sum;
    p.cnt = pl.cnt + pr.cnt;
  }

  void modify(int u, int x, int v, int t) {
    // x 位置加上 t 个 v
    if (p.l == p.r) {
      p.sum += 1ll * t * v;
      p.cnt += t;
      return;
    }
    int mid = (p.l + p.r) >> 1;
    if (x <= mid) {
      modify(lson, x, v, t);
    } else {
      modify(rson, x, v, t);
    }
    push_up(u);
  }

  LL query_sum(int u, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l <= p.l && p.r <= r) {
      return p.sum;
    }
    int mid = (p.l + p.r) >> 1;
    LL res = 0;
    if (l <= mid) {
      res += query_sum(lson, l, r);
    }
    if (r > mid) {
      res += query_sum(rson, l, r);
    }
    return res;
  }

  int query_cnt(int u, int l, int r) {
    if (l <= p.l && p.r <= r) {
      return p.cnt;
    }
    int mid = (p.l + p.r) >> 1;
    int res = 0;
    if (l <= mid) {
      res += query_cnt(lson, l, r);
    }
    if (r > mid) {
      res += query_cnt(rson, l, r);
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
  LL negtivesum = 0;

  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];

    if (a[i] > 0) {
      postive.push_back(a[i]);
    } else {
      negtivesum += a[i];
    }
  }

  std::vector<PII> change(q);
  for (auto &[x, v] : change) {
    std::cin >> x >> v;
    if (v > 0) {
      postive.push_back(v);
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
      st.modify(1, rnk[a[i]], a[i], 1);
    }
  }

  for (auto &[x, v] : change) {
    if (a[x] > 0) {
      st.modify(1, rnk[a[x]], a[x], -1);
    } else {
      negtivesum -= a[x];
    }

    a[x] = v;

    if (a[x] > 0) {
      st.modify(1, rnk[a[x]], a[x], 1);
    } else {
      negtivesum += a[x];
    }

    int l = 0, r = postive.size() - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (st.query_sum(1, 1, mid) + negtivesum <= 0) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }

    LL rest = -(st.query_sum(1, 1, l) + negtivesum);
    int k = st.query_cnt(1, l + 1, l + 1) and l + 1 < (int)postive.size()
                ? st.query_cnt(1, 1, l) + rest / postive[l + 1]
                : st.query_cnt(1, 1, l);
    std::cout << k + 1 << '\n';
  }
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