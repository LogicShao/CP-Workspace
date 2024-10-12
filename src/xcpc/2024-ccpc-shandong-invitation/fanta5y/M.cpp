#include <bits/stdc++.h>

#define multi_test 0
#define DEBUG 1

using PII = std::pair<int, int>;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> f(2 * n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> f[i];
    f[i + n] = f[i];
  }

  // std::vector<PII> points(n + 1);
  // for (int i = 1; i <= n; ++i) {
  //   std::cin >> points[i].first >> points[i].second;
  // }

  std::vector<int> ids;
  auto getLongestPalindromicSubsequence = [&](std::vector<int> f, int delta) {
    auto dp = std::vector(n + 1, std::vector(n + 1, 0));
    auto rf = f;
    std::reverse(rf.begin() + 1, rf.end());

    for (int i = 1; i <= n; ++i) {
      std::cerr << f[i] << ' ';
    }
    std::cerr << '\n';

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (f[i] == rf[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    std::vector<int> res;
    {
      int i = n, j = n;
      while (i > 0 and j > 0) {
        if (f[i] == rf[j]) {
          res.push_back(f[i]);
          --i, --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
          --i;
        } else {
          --j;
        }
      }

      std::reverse(res.begin(), res.end());
      for (auto x : res) {
        std::cerr << x << ' ';
      }
      std::cerr << '\n';
    }

    if (res.size() > ids.size()) {
      ids = std::move(res);
    }
  };

  for (int i = 1; i <= n; ++i) {
    getLongestPalindromicSubsequence({f.begin() + i - 1, f.begin() + i + n},
                                     i - 1);
  }

  std::cout << ids.size() << '\n';
  for (int id : ids) {
    std::cout << id << ' ';
  }
  std::cout << '\n';
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