#include <bits/stdc++.h>

#define multi_test 0

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<std::set<int>> row(n + 1), col(m + 1); // 行列的点集
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      row[i].insert(j);
      col[j].insert(i);
    }
  }

  auto erase = [&](int x, int y) {
    if (x == -1 or y == -1)
      return;

    row[x].erase(y);
    col[y].erase(x);
  };

  // auto dout = [&](int delx, int dely) {
  //   std::cerr << std::format("del {} {}\n", delx, dely);
  //   for (int i = 1; i <= n; ++i) {
  //     for (int j = 1; j <= m; ++j) {
  //       std::cerr << (row[i].count(j) ? 1 : 0) << ' ';
  //     }
  //     std::cerr << '\n';
  //   }
  //   std::cerr << "----------------\n";
  // };

  while (q--) {
    int x, y;
    std::cin >> x >> y;

    auto &r = row[x], &c = col[y];

    if (r.count(y)) {
      erase(x, y);
    } else {
      int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
      // (x1, y1): 前一个点 (x2, y2): 后一个点
      auto rit = r.lower_bound(y);
      if (rit != r.end()) {
        x1 = x;
        y1 = *rit;
      }
      if (rit != r.begin()) {
        x2 = x;
        y2 = *std::prev(rit);
      }

      int x3 = -1, x4 = -1, y3 = -1, y4 = -1;
      auto cit = c.lower_bound(x);
      if (cit != c.end()) {
        x3 = *cit;
        y3 = y;
      }
      if (cit != c.begin()) {
        x4 = *std::prev(cit);
        y4 = y;
      }

      erase(x1, y1);
      erase(x2, y2);
      erase(x3, y3);
      erase(x4, y4);
    }

    // dout(x, y);
  }

  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += row[i].size();
  }
  std::cout << cnt << '\n';
}

int main() {
  // freopen("data.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  // std::cerr.tie(nullptr);

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}