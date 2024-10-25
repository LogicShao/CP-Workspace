#include <bits/stdc++.h>

#define multi_test 0
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;
using constStrRef = const std::string &;

template <bool added = false> LL solve(constStrRef s, constStrRef t) {
  int n = s.size(), m = t.size();
  int N = n + 10, M = m + 10;
  // f[i, j]表示后缀s[i]和s[j]可以匹配的最长前缀
  auto f = std::vector(N, std::vector(N, 0));
  // g[i, j]表示前缀s[i]和s[j]可以匹配的最长后缀
  auto g = std::vector(N, std::vector(M, 0));
  // h[j, i]表示s[i, j]在t中出现的次数的前缀和
  auto h = std::vector(N, std::vector(N, 0ll));

  for (int i = n; i; --i) {
    for (int j = n; j >= i; --j) {
      if (s[i - 1] == s[j - 1]) {
        f[i][j] = f[i + 1][j + 1] + 1;
      }
    }
  }

  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        g[i][j] = g[i - 1][j - 1] + 1;
      }

      if constexpr (not added) {
        // s[i-g[i][j]+1, i] ... s[i][i] 在t中都多出现一次
        ans += g[i][j];
      }

      // [i, i-g[i][j]+1] ... [i, i] 区间加一
      // 由于 [j, i] j>i 没有意义 所以我们可以不需要减一
      h[i][i - g[i][j] + 1] += 1;
    }
  }

  // 求前缀和
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      h[i][j] += h[i][j - 1];
    }
  }

  // 此时 h[j,i] 表示的是 s[i,j] 在t中出现的次数
  // 再求一次前缀和
  // 于是乎 h[j,r]-h[j,l-1] 表示的是 s[l,r] 的所有后缀在t中出现的次数
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      h[i][j] += h[i][j - 1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 2; j <= n; ++j) {
      if (not f[i][j])
        continue;
      int pos = i + f[i][j];
      ans += h[j - 1][std::min(j - 1, pos)] - h[j - 1][i];
    }
  }

  return ans;
}

void solve() {
  std::string s, t;
  std::cin >> s >> t;

  auto res =
      solve(s, t) + solve<true>({t.rbegin(), t.rend()}, {s.rbegin(), s.rend()});

  std::cout << res << '\n';
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