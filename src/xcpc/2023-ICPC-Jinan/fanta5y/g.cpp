#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

constexpr int mod = 1e9 + 7;

LL fpow(LL a, LL b, LL mod) {
  LL res = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
  }
  return res;
}

struct DSU {
  int n;
  std::vector<int> fa;

  DSU(int n) : n(n), fa(n) { std::iota(fa.begin(), fa.end(), 0); }

  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

  void merge(int x, int y) { fa[find(x)] = find(y); }

  bool same(int x, int y) { return find(x) == find(y); }

  int count() { // count the number of connected components
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += fa[i] == i;
    }
    return res;
  }
};

int solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] = "#" + a[i];
  }

  std::vector<std::vector<int>> pos(m + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      auto &s = a[i];
      if (s[j] == '0')
        continue;
      pos[j].emplace_back(i);
      if (m % 2 == 1 and j == m / 2 + 1) { // 如果是中心点
        if (pos[j].size() > 1)
          return 0;
      } else { // 如果不是中心点
        if (pos[j].size() + pos[m - j + 1].size() > 2)
          return 0;
      }
    }
  }

  DSU dsu(2 * n + 1);
  for (int l = 1, r = m; l < r; ++l, --r) {
    auto &pl = pos[l], &pr = pos[r];
    if (pl.size() + pr.size() != 2)
      continue;

    if (pl.size() == 2) {
      int u = pl[0], v = pl[1];
      dsu.merge(u, v + n);
      dsu.merge(v, u + n);
    } else if (pr.size() == 2) {
      int u = pr[0], v = pr[1];
      dsu.merge(u, v + n);
      dsu.merge(v, u + n);
    } else {
      int u = pl[0], v = pr[0];
      dsu.merge(u, v);
      dsu.merge(u + n, v + n);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (dsu.same(i, i + n))
      return 0;
  }

  return fpow(2, dsu.count() / 2, mod);
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
    std::cout << solve() << '\n';
  }
}