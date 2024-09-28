#include <bits/stdc++.h>

#define multi_test 0
#define debug 0

using LL = long long;

constexpr int inf = 0x3f3f3f3f;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  a[0] = inf;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::stack<int> s;
  std::vector<LL> b(n + 1);

  s.push(0);
  for (int i = 1; i <= n; ++i) {
    while (a[s.top()] <= a[i]) {
      s.pop();
    }
    // 距离最近的比 a[i] 大的元素下标为 s.top()
    // 可行的区间为 [max(1, s.top()), i)
    int l = std::max(1, s.top());
    int r = i - 1;
    b[l]++, b[r + 1]--;
    s.push(i);
  }

  for (int i = 1; i <= n; ++i) {
    b[i] += b[i - 1];
    std::cout << b[i] << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  if constexpr (debug) {
    freopen("data.in", "r", stdin);
    std::cerr.tie(nullptr);
  }

  int T = 1;
  if constexpr (multi_test) {
    std::cin >> T;
  }

  while (T--) {
    solve();
  }
}