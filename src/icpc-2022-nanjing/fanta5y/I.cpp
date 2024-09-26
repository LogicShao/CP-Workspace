#include <bits/stdc++.h>

#define multi_test 1

void solve() {
  std::string s;
  std::cin >> s;
  std::map<char, int> cnt;
  for (auto c : s) {
    cnt[c]++;
  }
  int mx = 0;
  for (auto [_, val] : cnt) {
    mx = std::max(mx, val);
  }
  std::cout << s.size() - mx << '\n';
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