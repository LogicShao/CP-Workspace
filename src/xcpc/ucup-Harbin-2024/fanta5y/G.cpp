#include <bits/stdc++.h>

#define multi_test 0
#define DEBUG 1

using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<bool> isbusy(n + 1);
  for (int i = 1; i <= k; ++i) {
    int a;
    std::cin >> a;
    isbusy[a] = true;
  }

  auto G = std::vector<std::vector<int>>(n + 1);
  auto add = [&](int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  };

  while (m--) {
    int u, v;
    std::cin >> u >> v;
    add(u, v);
    add(v, u);
  }

  auto inivite = std::vector<std::vector<int>>(n + 1);
  auto vis = std::vector<bool>(n + 1);
  std::function<int(int)> dfs = [&](int u) -> int {
    int siz = 1;
    vis[u] = true;
    for (auto v : G[u]) {
      if (vis[v])
        continue;
      if (isbusy[v]) {
        inivite[u].emplace_back(v);
        siz += 1;
        vis[v] = true;
        continue;
      }
      siz += dfs(v);
      inivite[u].emplace_back(v);
    }
    return siz;
  };

  bool flag = false;
  int root = -1;
  for (int i = 1; i <= n; ++i) {
    if (isbusy[i])
      continue;
    if (dfs(i) == n) {
      flag = true;
      root = i;
      break;
    }
    break;
  }

  auto out = [&]() -> void {
    std::queue<int> q;
    q.push(root);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      if (inivite[u].empty())
        continue;

      std::cout << u << ' ' << inivite[u].size();
      for (auto v : inivite[u]) {
        std::cout << ' ' << v;
        q.push(v);
      }

      std::cout << '\n';
    }
  };

  if (flag) {
    std::cout << "Yes\n";
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
      cnt += not inivite[i].empty();
    std::cout << cnt << '\n';

    out();
  } else {
    std::cout << "No\n";
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