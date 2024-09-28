#include <bits/stdc++.h>

#define multi_test 0
#define debug 0

struct MergeFindSet {
  std::vector<int> fa, sz;
  std::vector<std::vector<int>> st; // 维护联通块内前10大的数字

  MergeFindSet(int n) : fa(n + 1), sz(n + 1), st(n + 1) {
    for (int i = 1; i <= n; ++i) {
      fa[i] = i;
      sz[i] = 1;
      st[i].push_back(i);
    }
  }

  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return;
    if (sz[x] < sz[y])
      std::swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
    std::vector<int> tmp;
    std::merge(st[x].begin(), st[x].end(), st[y].begin(), st[y].end(),
               std::back_inserter(tmp),
               std::greater<int>()); // 合并两个有序数组
    while (tmp.size() > 10)
      tmp.pop_back();
    st[x] = std::move(tmp);
    st[y].clear();
  }

  int query(int x, int k) {
    x = find(x);
    if (k > st[x].size())
      return -1;
    return st[x][k - 1];
  }
};

void solve() {
  int n, Q;
  std::cin >> n >> Q;

  MergeFindSet mfs(n);
  while (Q--) {
    int opt;
    std::cin >> opt;

    if (opt == 1) {
      int u, v;
      std::cin >> u >> v;

      mfs.merge(u, v);
    } else {
      int v, k;
      std::cin >> v >> k;

      std::cout << mfs.query(v, k) << '\n';
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (debug) {
    freopen("data.in", "r", stdin);
    std::cerr.tie(nullptr);
  }

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}