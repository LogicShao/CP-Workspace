#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

bool solve(std::string &s) {
  int n = s.size();
  std::unordered_map<char, int> kind;
  kind['['] = kind[']'] = 1;
  kind['('] = kind[')'] = 2;

  for (int i = 0, j = 0, cnt = 0; i < n; i = j) {
    while (j < n and kind[s[j]] == kind[s[i]])
      ++j;
    int len = j - i;
    if (len >= 3)
      return false;
    if (len == 2) {
      cnt++;
      if (cnt == 3)
        return false;
    }
  }

  return true;
}

void solve() {
  std::string s;
  std::cin >> s;
  std::cout << (solve(s) ? "Yes" : "No") << '\n';
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