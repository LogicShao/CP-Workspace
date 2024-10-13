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
using PLL = std::pair<LL, LL>;

void solve() {
  int n;
  std::cin >> n;

  std::vector<LL> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<PLL> stk;
  for (int i = 1; i <= n; ++i) {
    LL sum = a[i], cnt = 1;
    while (stk.size() and stk.back().first >= sum / cnt) {
      sum += stk.back().first * stk.back().second;
      cnt += stk.back().second;
      stk.pop_back();
    }
    stk.emplace_back(sum / cnt, cnt - sum % cnt);
    if (sum % cnt)
      stk.emplace_back(sum / cnt + 1, sum % cnt);
  }

  std::cout << stk.back().first - stk.front().first << '\n';
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