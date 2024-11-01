#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

int bits(int x) {
  int res = 0;
  for (; x; x >>= 1)
    res++;
  return res;
}

void solve1(int n) {
  std::set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }

  std::vector<int> a, b;
  for (int x = bits(n) - 1; x >= 0; --x) {
    int u = 1 << x, v = u - 1;
    if (u == 1 and not s.count(1)) {
      while (not s.count(u))
        u += 2;
    }
    a.push_back(u);
    s.erase(u);
    if (v > 0) {
      b.push_back(v);
      s.erase(v);
    }
  }

  while (a.size() < n / 2) {
    a.push_back(*s.begin());
    s.erase(s.begin());
  }
  while (b.size() < n / 2) {
    b.push_back(*s.begin());
    s.erase(s.begin());
  }

  int res = 0;
  for (auto it1 = a.rbegin(), it2 = b.rbegin(); it1 != a.rend(); ++it1, ++it2) {
    res = res & *it2 | *it1;
  }

  std::cout << res << '\n';
  for (auto it1 = a.rbegin(), it2 = b.rbegin(); it1 != a.rend(); ++it1, ++it2) {
    std::cout << *it2 << ' ' << *it1 << ' ';
  }
  std::cout << '\n';
}

void solve2(int n) {
  std::set<int> s;
  for (int i = 1; i < n; ++i) {
    s.insert(i);
  }

  std::vector<int> a, b;
  for (int bit = 30; bit >= 0; --bit) {
    int u = n & (1 << bit);
    if (u) {
      int v = u - 1;
      if (u == 1 and not s.count(1)) {
        while (not s.count(u))
          u += 2;
      }
      a.push_back(u);
      s.erase(u);
      if (v > 0) {
        b.push_back(v);
        s.erase(v);
      }
    }
  }

  while (a.size() < n / 2) {
    a.push_back(*s.begin());
    s.erase(s.begin());
  }
  while (s.size()) {
    b.push_back(*s.begin());
    s.erase(s.begin());
  }

  int res = 0;
  for (auto it1 = a.rbegin(), it2 = b.rbegin(); it1 != a.rend(); ++it1, ++it2) {
    res = res & *it2 | *it1;
  }
  res = res & n;

  std::cout << res << '\n';
  for (auto it1 = a.rbegin(), it2 = b.rbegin(); it1 != a.rend(); ++it1, ++it2) {
    std::cout << *it2 << ' ' << *it1 << ' ';
  }
  std::cout << n << '\n';
}

void solve() {
  int n;
  std::cin >> n;

  if (n % 2 == 0)
    solve1(n);
  else
    solve2(n);
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