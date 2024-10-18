#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 1

using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a_(n);
  int cnt2 = 0;
  for (auto &x : a_) {
    std::cin >> x;
    while (x % 2 == 0) {
      x /= 2;
      ++cnt2;
    }
  }

  std::sort(a_.begin(), a_.end());

  auto check = [&](int x) -> bool {
    int cnt = cnt2;
    auto a = a_;
    for (int i = n - 1; i >= n - x and cnt > 0; --i) {
      auto &t = a[i];
      while (t < x and cnt > 0) {
        t *= 2;
        --cnt;
      }
    }
    for (int i = n - 1; i >= n - x; --i) {
      if (a[i] < x) {
        return false;
      }
    }
    return true;
  };

  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }

  std::cout << l << '\n';
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