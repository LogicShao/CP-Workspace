#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n, x;
  std::cin >> n >> x;

  std::vector a(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  LL res = 0, delta = 0, last = 0;
  for (int i = 1; i <= n - x + 1; ++i) {
    int diff = a[i] - a[i - 1];
    int w = n - i + 1;
    LL all = (LL)w * diff + last;
    res += all / x;
    last = all % x;
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