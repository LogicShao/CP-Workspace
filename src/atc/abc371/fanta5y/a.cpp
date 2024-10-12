#include <bits/stdc++.h>

#define multi_test 0

void solve() {
  std::string ab, ac, bc;
  std::cin >> ab >> ac >> bc;
  int rka = int(ab == ">") + (ac == ">");
  int rkb = int(ab == "<") + (bc == ">");
  int rkc = int(ac == "<") + (bc == "<");
  if (rka == 1) {
    std::cout << "A\n";
  } else if (rkb == 1) {
    std::cout << "B\n";
  } else {
    std::cout << "C\n";
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