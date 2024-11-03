#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n;
  std::cin >> n;

  if (n == 1 or n == 3) {
    std::cout << -1 << '\n';
    return;
  }

  if (n == 2) {
    std::cout << 66 << '\n';
    return;
  }

  if (n & 1) {
    std::cout << std::string(n - 4, '3') + "6366" << '\n';
  } else {
    std::cout << std::string(n - 2, '3') + "66" << '\n';
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