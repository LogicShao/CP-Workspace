#include <bits/stdc++.h>

#define multi_test 0

using LL = long long;

void solve() {
  int n, k, m, c, d;
  std::cin >> n >> k >> m >> c >> d;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  auto check = [&](LL x) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      cnt += a[i] >= x;
    }

    if (cnt >= k) {
      return true;
    }

    std::vector<int> f(n + 10, 0);
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= x) {
        continue;
      }

      int R = std::min(i - 1, m - 1);
      LL mx = a[i] + c + (LL)d * R;
      if (mx < x) {
        continue;
      }

      f[std::max(m, i)]++;
      LL mn = a[i] + c;
      if (mn >= x) {
        f[std::min(n + 1, i + m)]--;
      } else {
        int pos = (x - mn - 1) / d;
        f[std::min(n + 1, i + m - pos - 1)]--;
      }
    }

    for (int i = m; i <= n; ++i) {
      cnt += f[i];
      if (cnt >= k) {
        return true;
      }
    }
    return false;
  };

  LL l = 0, r = 1e16;
  while (l < r) {
    LL mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }

  std::cout << l << '\n';
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