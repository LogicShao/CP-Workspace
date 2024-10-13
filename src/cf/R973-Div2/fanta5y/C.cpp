#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

#if DEBUG
#define dbg(x)                                                                 \
  do {                                                                         \
    std::cerr << #x << " = " << x << '\n';                                     \
  } while (0)
#endif

using LL = long long;
using PII = std::pair<int, int>;

int ask(const std::string &t) {
  std::cout << "? " << t << std::endl;
  int res;
  std::cin >> res;
  return res;
}

void answer(const std::string &t) { std::cout << "! " << t << std::endl; }

void solve() {
  int n;
  std::cin >> n;

  std::string s;
  bool is_prefix = true;
  for (int i = 1; i <= n; ++i) {
    if (is_prefix) {
      s.push_back('0');
      if (ask(s))
        continue;
      s.back() = '1';
      if (ask(s))
        continue;
      is_prefix = false;
      s.pop_back();
    }
    s = "0" + s;
    if (ask(s))
      continue;
    s[0] = '1';
  }

  answer(s);
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