#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

constexpr int mod = 1e9 + 7;

LL fpow(LL a, LL b, LL mod) {
  LL res = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
  }
  return res;
}

int solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] = "#" + a[i];
  }

  int cnt = 0;
  std::vector<int> pos(m + 1);

  auto can_place = [&](const std::string &s) {
    for (int i = 1; i <= m; ++i) {
      if (s[i] == '1') {
        if (pos[i] != 0)
          return false;
      }
    }
    return true;
  };

  auto place = [&](const std::string &s, int row) {
    for (int i = 1; i <= m; ++i) {
      if (s[i] == '1') {
        pos[i] = row;
      }
    }
  };

  for (int i = 1; i <= n; ++i) {
    auto &s = a[i];
    auto ss = s;
    std::reverse(ss.begin() + 1, ss.end());

    bool flag1 = can_place(s);
    bool flag2 = can_place(ss);

    if (flag1 and flag2) {
      ++cnt;
      place(s, i);
    } else if (flag1) {
      place(s, i);
    } else if (flag2) {
      place(ss, i);
    } else {
      return 0;
    }
  }

  return fpow(2, cnt, mod);
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
    std::cout << solve() << '\n';
  }
}