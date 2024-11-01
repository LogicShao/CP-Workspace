#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 1

using LL = long long;
using PII = std::pair<int, int>;

int lowbit(int x) { return x & -x; }

int bitcnt(int x) {
  int res = 0;
  while (x) {
    x -= lowbit(x);
    ++res;
  }
  return res;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 1);

  auto calc = [&]() {
    int k = 0;
    for (int i = 1; i <= n; ++i) {
      if (i & 1) {
        k &= a[i - 1];
      } else {
        k |= a[i - 1];
      }
    }
    return k;
  };

  int k = 0;
  do {
    k = std::max(k, calc());
  } while (std::next_permutation(a.begin(), a.end()));

  std::cout << n << ' ' << k << '\n';

  std::iota(a.begin(), a.end(), 1);
  do {
    if (calc() == k) {
      for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
      }
    }
  } while (std::next_permutation(a.begin(), a.end()));
  std::cout << "***\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (DEBUG) {
    std::cerr.tie(nullptr);
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  }

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}