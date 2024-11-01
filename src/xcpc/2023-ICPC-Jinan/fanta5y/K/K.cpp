#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using LD = long double;
using PII = std::pair<int, int>;

template <typename T> void chkmax(T &a, const T &b) {
  if (a < b) {
    a = b;
  }
}

struct midnum {
  std::multiset<int> big, small;
  LL bigsum, smallsum;

  midnum() : bigsum(0), smallsum(0) {}

  void balance() {
    while (big.size() > small.size()) {
      smallsum += *big.begin();
      bigsum -= *big.begin();
      small.insert(*big.begin());
      big.erase(big.begin());
    }
    while (small.size() > big.size() + 1) {
      bigsum += *small.rbegin();
      smallsum -= *small.rbegin();
      big.insert(*small.rbegin());
      small.erase(--small.end());
    }
  }

  void insert(int x) {
    if (small.empty() or x <= *small.rbegin()) {
      small.insert(x);
      smallsum += x;
    } else {
      big.insert(x);
      bigsum += x;
    }
    balance();
  }

  void erase(int x) {
    if (small.count(x)) {
      small.erase(small.find(x));
      smallsum -= x;
    } else {
      big.erase(big.find(x));
      bigsum -= x;
    }
    balance();
  }

  int getmid() { return *small.rbegin(); }
};

void solve() {
  int n;
  LL k;
  std::cin >> n >> k;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] -= i;
  }

  midnum m_mid;

  auto check = [&](int l, int r) -> bool {
    if (l == r)
      return true;
    LL mid = m_mid.getmid();
    LL s1 = m_mid.small.size(), s2 = m_mid.big.size();
    LL sum1 = m_mid.smallsum, sum2 = m_mid.bigsum;
    LL cost = s1 * mid - sum1 + sum2 - s2 * mid;
    return cost <= k;
  };

  int res = 0;
  int l = 1, r = 1;
  auto upd = [&]() { chkmax(res, r - l + 1); };

  while (r <= n) {
    m_mid.insert(a[r]);
    while (not check(l, r)) {
      m_mid.erase(a[l++]);
    }
    upd();
    ++r;
  }

  std::cout << res << '\n';
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