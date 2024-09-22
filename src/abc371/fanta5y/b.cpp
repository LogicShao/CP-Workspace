#include <bits/stdc++.h>

#define multi_test 0

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> st(n + 1, 0);
  for (int i = 1; i <= m; ++ i) {
    int a;
    std::string b;
    std::cin >> a >> b;
    if (not st[a] and b == "M") {
      std::cout << "Yes\n";
      st[a] = 1;
    } else {
      std::cout << "No\n";
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