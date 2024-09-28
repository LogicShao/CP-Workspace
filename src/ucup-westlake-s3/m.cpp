#include <bits/stdc++.h>
#include <cmath>

#define multi_test 1

using PII = std::pair<int, int>;
using LL = long long;

constexpr int inf = 0x3f3f3f3f;

template <typename T> void chkmin(T &a, const T &b) {
  if (a > b) {
    a = b;
  }
}

struct edge {
  int v, c, l;
};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  auto g = std::vector(n + 1, std::vector<edge>());
  while (m--) {
    int u, v, c, l;
    std::cin >> u >> v >> c >> l;
    g[u].emplace_back(v, c, l);
    g[v].emplace_back(u, c, l);
  }

  std::map<int, std::vector<PII>> tickets; // first: dist, second: rank
  for (int i = 1; i <= k; ++i) {
    int a, b;
    std::cin >> a >> b;
    tickets[a].emplace_back(b, i);
  }

  std::map<int, std::vector<int>> tickets_min_rank; // 维护tickets中的后缀最小值
  for (auto &[_, v] : tickets) {
    std::sort(v.begin(), v.end());
    auto tmp = std::vector<int>(v.size());
    tmp[v.size() - 1] = v.back().second;
    for (int i = v.size() - 2; i >= 0; --i) {
      tmp[i] = std::min(tmp[i + 1], v[i].second);
    }
    tickets_min_rank[_] = std::move(tmp);
  }

  std::vector<bool> arrivable(n + 1, false);
  std::vector<int> f(n + 1, inf); // f[i]: 表示到达i点最小使用的车票

  std::queue<int> q;
  q.push(1);
  f[1] = 0;
  arrivable[1] = true;

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (auto [v, c, l] : g[u]) {
      if (tickets.count(c) == 0)
        continue;

      auto &v_tickets = tickets[c];
      auto it =
          std::lower_bound(v_tickets.begin(), v_tickets.end(), PII{l, -1});
      if (it == v_tickets.end())
        continue;

      int ticket_id = tickets_min_rank[c][it - v_tickets.begin()];
      LL ticket_val = it->first;
      if (ticket_id <= f[u]) // 如果用到之前的车票，那么是非法的
        continue;

      std::vector<int>
          new_arrivable; // 使用ticket_val的车票可以到达的(之前没有到达过的)点
      std::function<void(int, int)> dfs = [&](int u, int ticket_val) -> void {
        if (ticket_val <= 0)
          return;
        for (auto [_v, _c, _l] : g[u]) {
          if (_c == c and not arrivable[_v] and ticket_val >= _l) {
            arrivable[_v] = true;
            new_arrivable.push_back(_v);
            dfs(_v, ticket_val - _l);
          }
        }
      };

      dfs(u, ticket_val); // 从u点出发，使用ticket_val的车票可以到达的点

      for (int v : new_arrivable) {
        chkmin(f[v], ticket_id);
        q.push(v);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << arrivable[i];
  }
  std::cout << '\n';
}

int main() {
  freopen("data.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cerr.tie(nullptr);

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}