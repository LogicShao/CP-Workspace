#include <bits/stdc++.h>

#define multi_test 1

void solve() {
  std::string s;
  std::cin >> s;

  int n = s.size();
  for (int i = 0; i < n; ++ i) {
    if (s[i] == s[(i - 1 + n) % n]) {
      std::cout << i << '\n';
      return;
    }
  }

  std::cout << -1 << '\n';
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