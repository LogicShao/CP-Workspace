#include <bits/stdc++.h>

#define multi_test 0

using LL = long long;

constexpr int mod = 998244353;

LL momo(LL x) {
  return (x % mod + mod) % mod;
}

void solve() {
  int n;
  LL k;
  std::cin >> n >> k;

  std::vector<LL> a(n + 1), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    b[i] = b[i - 1] + a[i];
  }

  std::vector<LL> f(n + 1);
  std::map<LL, LL> mp;

  LL pre = f[0] = mp[0] = 1;

  for (int i = 1; i <= n; ++ i) {
    f[i] = momo(pre - mp[b[i] - k]);
    mp[b[i]] = momo(mp[b[i]] + f[i]);
    pre = momo(pre + f[i]);
  }

  std::cout << f[n] << '\n';
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