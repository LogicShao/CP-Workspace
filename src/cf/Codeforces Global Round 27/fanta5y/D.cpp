#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 1

using LL = long long;
using ULL = unsigned long long;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;

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

LL momo(LL x) { return (x % mod + mod) % mod; }

void solve() {
  int n;
  std::cin >> n;

  auto stk = std::vector<PLL>();
  LL sum = 0;

  for (int i = 1; i <= n; ++i) {
    int xi;
    std::cin >> xi;

    LL r = std::countr_zero(ULL(xi)), x = xi >> r;
    while (not stk.empty()) {
      if (r >= 30 or stk.back().first <= (x << r)) {
        // 如果之后的数字更大，那么我们把之前的2乘到这个数字上
        r += stk.back().second;
        // 之前的数字因为使用了所以2的因子，所以舍弃掉
        sum += stk.back().first;
        stk.pop_back();
      } else {
        break;
      }
    }

    if (r == 0) { // 如果没有2的因子，那么直接加到答案上
      sum += x;
    } else {
      stk.emplace_back(x, r);
    }

    LL add = 0;
    for (auto [x, r] : stk) {
      add = (add + fpow(2, r, mod) * x % mod) % mod;
    }

    std::cout << (sum + add) % mod << " \n"[i == n];
  }
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