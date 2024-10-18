#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 1

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N = 1e6 + 10;
int prime[N], cnt;
bool st[N];

void get_primes(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!st[i])
      prime[cnt++] = i;
    for (int j = 0; prime[j] <= n / i; ++j) {
      st[prime[j] * i] = true;
      if (i % prime[j] == 0)
        break;
    }
  }
}

void prework() {
  get_primes(1e6);

  for (int i = 0; i < 10; ++ i) {
    std::cerr << prime[i] << ' ';
  }
  std::cerr << '\n';
}

int get_cnt_of_primes_div(int x) {
  int res = 0;
  for (int i = 0; prime[i] <= x / prime[i]; ++i) {
    if (x % prime[i] == 0) {
      while (x % prime[i] == 0) {
        x /= prime[i];
        ++res;
      }
    }
  }
  if (x > 1) {
    ++res;
  }
  return res;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  int cnt = 0;
  for (auto &x : a) {
    std::cin >> x;
    if (get_cnt_of_primes_div(x) >= 3) {
      ++cnt;
    }
  }

  std::cout << n - cnt + (cnt + 1) / 2 << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (DEBUG) {
    std::cerr.tie(nullptr)->sync_with_stdio(false);
    freopen("data.in", "r", stdin);
  }

  prework();

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}