#include <bits/stdc++.h>

#define multi_test 0

using LL = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> pos(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    pos[a[i]].push_back(i);
  }

  auto calc = [&](int x, int y) -> LL {
    if (x > y)
      return 0;
    int len = y - x + 1;
    return 1LL * len * (len + 1) / 2;
  };

  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    auto &p = pos[i];
    if (p.empty()) {
      continue;
    }
    LL tmp = 0;
    tmp += calc(1, p.front() - 1) + calc(p.back() + 1, n);
    for (int i = 1; i < p.size(); ++ i) {
      tmp += calc(p[i - 1] + 1, p[i] - 1);
    }
    ans += calc(1, n) - tmp;
  }

  std::cout << ans << '\n';
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