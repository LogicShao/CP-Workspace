#include <bits/stdc++.h>

#define multi_test 0
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N = 110;
int f[N];

int g(int x) {
  std::vector<int> tmp;
  while (x) {
    tmp.push_back(x & 1);
    x >>= 1;
  }
  int res = 0;
  for (int i = tmp.size() - 1; i >= 0; i -= 2) {
    res += tmp[i];
  }
  return res;
}

std::string to_bin(int x) {
  std::string res;
  while (x) {
    res.push_back('0' + (x & 1));
    x >>= 1;
  }
  std::reverse(res.begin(), res.end());
  return res;
}

void solve() {
  std::ofstream fout("data.out");
  int n = 100;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] + g(i);
    fout << i << "\t\t\t" << f[i] << "\t\t\t" << to_bin(i) << "\n";
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (DEBUG) {
    std::cerr.tie(nullptr)->sync_with_stdio(false);
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