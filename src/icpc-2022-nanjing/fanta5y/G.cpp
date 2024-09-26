#include <bits/stdc++.h>

#define multi_test 1

using LL = long long;

constexpr LL INF = 1e9;

struct fr {
  LL a, b;

  fr(LL _a, LL _b) : a(_a), b(_b) {
    LL t = std::__gcd(a, b);
    a /= t, b /= t;
  }

  bool operator<(const fr &f) const { return a * f.b < b * f.a; }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> opt(n);
  for (auto &i : opt) {
    std::cin >> i;
  }

  LL a = 1, b = 1;
  int sel = 0;
  for (auto i : opt) {
    if (i == 1) {
      a++, b++;
    } else if (i == -1) {
      b--;
      while (sel > 0 and b <= 0) {
        a++, b += 2;
        sel--;
      }
      if (b <= 0) {
        std::cout << -1 << '\n';
        return;
      }
    } else {
      if (b == 1) {
        a++, b++;
      } else {
        b--;
        sel++;
      }
    }
  }

  LL t = std::__gcd(a, b);
  a /= t, b /= t;

  std::cout << a << ' ' << b << '\n';
}

int main() {
  freopen("data.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}