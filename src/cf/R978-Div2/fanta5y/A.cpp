#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n, r;
  std::cin >> n >> r;

  int res = 0, sum = 0;
  std::vector<int> a(n);
  for (auto &x : a) {
    std::cin >> x;
    r -= x / 2;
    res += x / 2 * 2;
    x %= 2;
    sum += x;
  }

  if (sum <= r) {
    res += sum;
  } else {
    res += 2 * r - sum;
  }

  std::cout << res << '\n';
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