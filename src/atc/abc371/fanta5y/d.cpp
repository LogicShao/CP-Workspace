#include <bits/stdc++.h>

#define multi_test 0

using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n;
  std::cin >> n;

  std::vector<PII> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i].first;
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i].second;
  }

  std::sort(a.begin() + 1, a.end(),
            [](const PII &x, const PII &y) { return x.first < y.first; });

  std::vector<LL> s(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + a[i].second;
  }

  int Q;
  std::cin >> Q;

  while (Q--) {
    int l, r;
    std::cin >> l >> r;
    int idl = std::upper_bound(a.begin() + 1, a.end(), PII(l - 1, 0),
                               [](const PII &x, const PII &y) {
                                 return x.first < y.first;
                               }) -
              a.begin();
    int idr = std::upper_bound(a.begin() + 1, a.end(), PII(r, 0),
                               [](const PII &x, const PII &y) {
                                 return x.first < y.first;
                               }) -
              a.begin() - 1;
    std::cout << s[idr] - s[idl - 1] << '\n';
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