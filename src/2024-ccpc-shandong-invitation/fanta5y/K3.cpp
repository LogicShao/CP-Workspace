#include <bits/stdc++.h>

#define multi_test 0

void solve() {
  int n;
  std::cin >> n;

  std::cout << "Yes\n";

  auto a = std::vector(n, std::vector(n, 0));
  for (int t = 0; t < n - 2; ++ t) {
    for (int i = t; i < n; ++ i) {
      a[t][i] = 2 * t + 1;
    }
    for (int i = t + 1; i < n; ++ i) {
      a[i][t] = 2 * t + 2;
    }
  }

  a[n - 1][n - 1] = 2 * n;
  a[n - 1][n - 2] = 2 * n - 1;
  a[n - 2][n - 1] = 2 * n - 2;
  a[n - 2][n - 2] = 2 * n - 3;

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      std::cout << a[i][j] << " \n"[j == n - 1];
    }
  }
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