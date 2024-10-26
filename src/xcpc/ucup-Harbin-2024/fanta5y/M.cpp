#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

int f(int a, int b) {
  for (int i = b; i >= 2; --i) {
    if (a % i == 0) {
      return a / i;
    }
  }
  return a;
}

std::vector<int> get_divisors(int n) {
  std::vector<int> res;
  for (int i = 1; i <= n / i; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (i * i != n) {
        res.push_back(n / i);
      }
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}

void solve() {
  int n;
  std::cin >> n;

  LL ans = 1;
  auto divs = get_divisors(n);
  auto cnt = divs;
  for (int i = 1; i < cnt.size(); ++i) {
    cnt[i] = divs[i] - divs[i - 1];
  }
  std::reverse(cnt.begin() + 1, cnt.end());
  for (int i = 1; i < cnt.size(); ++i) {
    ans += 1LL * cnt[i] * divs[i];
  }

  // std::map<int, int> cnt;
  // for (int i = 1; i <= n; ++i) {
  //   cnt[f(n, i)]++;
  // }
  // for (auto [k, v] : cnt) {
  //   std::cerr << k << ' ' << v << '\n';
  // }

  std::cout << ans << '\n';
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