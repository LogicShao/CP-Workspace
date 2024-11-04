#include <bits/stdc++.h>

using LL = long long;

constexpr int N = 2e5 + 10;

LL w[N];

LL gcd(LL a, LL b) // 求最大公约数
{
  return b ? gcd(b, a % b) : a;
}

struct SegmentTree {
  struct Node {
    int l, r;
    LL sum, d;
  };

  std::vector<Node> tr;

  SegmentTree(int n) : tr(n << 2) {}

  void pushup(Node &u, Node &l, Node &r) // 由子区间信息更新父区间信息
  {
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
  }

  void pushup(int u) { pushup(tr[u], tr[u << 1], tr[u << 1 | 1]); }

  void build(int u, int l, int r) // 建树
  {
    tr[u].l = l, tr[u].r = r;
    if (l == r)
      tr[u].d = w[l] - w[l - 1], tr[u].sum = w[l] - w[l - 1];
    else {
      int mid = (l + r) >> 1;
      build(u << 1, l, mid);
      build(u << 1 | 1, mid + 1, r);
      pushup(u);
    }
  }

  void modify(int u, int x, LL v) // 修改
  {
    if (tr[u].r == x && tr[u].l == x)
      tr[u].d = tr[u].sum + v, tr[u].sum += v;
    else {
      int mid = (tr[u].l + tr[u].r) >> 1;
      if (mid >= x)
        modify(u << 1, x, v);
      else
        modify(u << 1 | 1, x, v);
      pushup(u);
    }
  }

  Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
      return tr[u];
    else {
      int mid = (tr[u].l + tr[u].r) >> 1;
      if (mid >= r)
        return query(u << 1, l, r);
      else if (mid < l)
        return query(u << 1 | 1, l, r);
      else {
        Node left = query(u << 1, l, r); // 如果当前访问区间的子区间横跨询问区间
        Node right = query(u << 1 | 1, l, r); // 则递归两个子区间
        Node res;                 // res相当于left和right的父区间
        pushup(res, left, right); // 相当于求right和left区间合并后的结果
        return res;
      }
    }
  }
};

LL mul_mod(LL a, LL b, LL mod) {
  LL res = 0;
  while (b) {
    if (b & 1)
      res = (res + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return res;
}

LL cnt_divisor(LL x) {
  LL res = 1;
  for (LL i = 2; i <= x / i; ++i) {
    if (x % i == 0) {
      LL cnt = 0;
      while (x % i == 0) {
        x /= i;
        ++cnt;
      }
      res *= (cnt + 1);
    }
  }
  if (x > 1)
    res *= 2;
  return res;
}

#define DEBUG 0
void solve() {
  int n, q;
  std::cin >> n >> q;

  std::vector<LL> a(n + 1);
  int zeros = 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    if (i == 1 or a[i] < a[i - 1]) {
      w[i] = i - 1;
      if (i == 1)
        zeros++;
    } else {
      w[i] = 0;
      zeros++;
    }
  }

  SegmentTree st(n + 5);
  st.build(1, 1, n);

  auto query = [&](int l, int r) {
    SegmentTree::Node left = st.query(1, 1, l), right = {0, 0, 0, 0};
    if (l + 1 <= r)
      right = st.query(1, l + 1, r);
    return std::abs(gcd(left.sum, right.d));
  };

  auto compute = [&]() -> LL {
    if (zeros == n)
      return n;
    return cnt_divisor(query(1, n));
  };

  std::cout << compute() << '\n';

  if constexpr (DEBUG) {
    for (int i = 1; i <= n; ++i) {
      std::cerr << st.query(1, 1, i).sum << ' ';
    }
    std::cerr << '\n';
  }

  while (q--) {
    LL p, v;
    std::cin >> p >> v;
    // 维护p位置
    auto pre1 = w[p], now1 = p == 1 or v < a[p - 1] ? p - 1 : 0;
    st.modify(1, p, now1 - pre1);
    if (p + 1 <= n)
      st.modify(1, p + 1, pre1 - now1);
    if (pre1 == 0)
      zeros--;
    if (now1 == 0)
      zeros++;
    // 维护p+1位置
    LL tmp;
    if (p + 1 <= n) {
      auto pre2 = w[p + 1], now2 = v > a[p + 1] ? p : 0;
      st.modify(1, p + 1, now2 - pre2);
      if (p + 2 <= n)
        st.modify(1, p + 2, pre2 - now2);
      if (pre2 == 0)
        zeros--;
      if (now2 == 0)
        zeros++;
      tmp = now2;
    }

    std::cout << compute() << '\n';

    a[p] = v;
    w[p] = now1;
    if (p + 1 <= n)
      w[p + 1] = tmp;

    if constexpr (DEBUG) {
      for (int i = 1; i <= n; ++i) {
        std::cerr << st.query(1, 1, i).sum << ' ';
      }
      std::cerr << '\n';
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (DEBUG) {
    std::cerr.tie(nullptr);
    freopen("data.in", "r", stdin);
  }

  int T;
  std::cin >> T;

  while (T--) {
    solve();
  }
}