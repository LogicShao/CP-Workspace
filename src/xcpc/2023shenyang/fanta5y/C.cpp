#include <bits/stdc++.h>

#define multi_test 0

void solve() {
  int x, y;
  std::cin >> x >> y;
  int res;
  if (x == 2 and y == 0) {
    res = 2;
  } else if (x == 1 and y == 0) {
    res = 3;
  } else if (x == 0 and y == 1) {
    res = 4;
  } else if (x == 0 and y == 0) {
    res = 4;
  } else if (x == 2 and y == 2) {
    res = 2;
  } else if (x == 1 and y == 1) {
    res = 3;
  } else if (x == 1 and y == 2) {
    res = 4;
  } else if (x == 2 and y == 1) {
    res = 2;
  } else {
    res = 6;
  }

  std::cout << res << '\n';
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