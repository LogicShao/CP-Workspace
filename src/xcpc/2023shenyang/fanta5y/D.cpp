#include <bits/stdc++.h>

#define multi_test 0
#define DEBUG 1

using LL = long long;
using PII = std::pair<int, int>;
using ULL = unsigned long long;

constexpr int N = 5e3 + 10, base = 1331;
char s[N], t[N];
ULL p[N];

struct hash_handler {
  ULL h[N];
  void init(const char *s) {
    h[0] = 0;
    for (int i = 1; s[i]; ++ i) {
      h[i] = h[i - 1] * base + s[i];
    }
  }
  ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
  }
} sh, th;

void pre_work() {
  p[0] = 1;
  for (int i = 1; i < N; ++ i) {
    p[i] = p[i - 1] * base;
  }
}

void solve() {
  std::cin >> (s + 1) >> (t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  sh.init(s);
  th.init(t);
  std::map<ULL, int> cnts, cntt;
  for (int i = 1; i <= n; ++ i) {
    for (int j = i; j <= n; ++ j) {
      cnts[sh.get(i, j)] ++;
    }
  }
  for (int i = 1; i <= m; ++ i) {
    for (int j = i; j <= m; ++ j) {
      cntt[th.get(i, j)] ++;
    }
  }
  LL res = 0;
  for (auto [k, v] : cnts) {
    if (not cntt.count(k)) continue;
    res += 1LL * v * cntt[k];
  }
  std::cout << res << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (DEBUG) {
    std::cerr.tie(nullptr);
    freopen("data.in", "r", stdin);
  }

  pre_work();

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}