#include <bits/stdc++.h>

#define multi_test 1

int f(int x) {
  int res = 0;
  while (x) {
    res = std::max(res, x % 10);
    x /= 10;
  }
  return res;
}

void solve() {
  int la, ra, lb, rb;
  std::cin >> la >> ra >> lb >> rb;

  int bound = 100;
  if (ra - la > bound and rb - lb > bound) {
    std::cout << 9 << '\n';
    return;
  }

  int res = 0;
  for (int i = la; i <= ra; ++i) {
    for (int j = lb; j <= rb; ++j) {
      res = std::max(res, f(i + j));
    }
  }

  std::cout << res << '\n';
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