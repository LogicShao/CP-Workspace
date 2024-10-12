#include <bits/stdc++.h>

#define multi_test 0

void solve() {
  int n, m;
  std::string s;
  std::cin >> n >> m;
  std::cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s.substr(i, 3) == "ABC") {
      ++cnt;
    }
  }
  while (m--) {
    int x;
    std::string c;
    std::cin >> x >> c;
    --x;
    for (int i = std::max(0, x - 2); i < std::min(n, x + 1); ++i) {
      if (s.substr(i, 3) == "ABC") {
        --cnt;
      }
    }
    s[x] = c[0];
    for (int i = std::max(0, x - 2); i < std::min(n, x + 1); ++i) {
      if (s.substr(i, 3) == "ABC") {
        ++cnt;
      }
    }
    std::cout << cnt << '\n';
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