#include <bits/stdc++.h>

#define multi_test 0

void solve() {
  int n = 5;
  // std::cin >> n;

  std::vector<std::vector<int>> a = {
    {1, 1, 1, 1, 1},
    {2, 3, 3, 3, 3},
    {2, 4, 5, 5, 5},
    {2, 4, 6, 7, 8},
    {2, 4, 6, 9, 10}
  };

  auto check = [&]() {
    int t = 0;
    std::set<int> s;
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        s.insert(a[x][y]);
      }
    }
    if (s.size() != 2 * n) {
      return false;
    }
    for (int x = 0; x < n; ++x) {
      for (int z = x + 1; z < n; ++z) {
        for (int y = 0; y < n; ++y) {
          for (int w = y + 1; w < n; ++w) {
            std::map<int, int> cnt;
            cnt[a[x][y]]++;
            cnt[a[z][y]]++;
            cnt[a[x][w]]++;
            cnt[a[z][w]]++;
            if (cnt.size() == 4) {
              t++;
            }
          }
        }
      }
    }
    return t == 1;
  };

  auto dfs = [&](auto &&self, int x, int y) -> bool {
    if (x == n) {
      return check();
    }
    if (y == n) {
      return self(self, x + 1, 0);
    }
    for (int i = 1; i <= 2 * n; ++i) {
      a[x][y] = i;
      if (self(self, x, y + 1)) {
        return true;
      }
    }
    return false;
  };

  if (check()) {
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        std::cout << a[x][y] << " \n"[y == n - 1];
      }
    }
  } else {
    std::cout << "No solution\n";
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