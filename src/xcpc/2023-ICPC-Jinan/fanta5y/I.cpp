#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 1

using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (auto &x : a) {
    std::cin >> x;
  }

  std::vector<PII> res;
  while (not std::is_sorted(a.begin(), a.end())) {
    bool flag = false;
    for (int i = 0; i < n and not flag; ++ i) {
      for (int j = n - 1; j > i and not flag; -- j) {
        if (a[i] > a[j]) {
          res.emplace_back(i + 1, j + 1);
          std::sort(a.begin() + i, a.begin() + j + 1);
          flag = true;
        }
      }
    }
  }

  std::cout << res.size() << '\n';
  for (const auto &[l, r] : res) {
    std::cout << l << ' ' << r << '\n';
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