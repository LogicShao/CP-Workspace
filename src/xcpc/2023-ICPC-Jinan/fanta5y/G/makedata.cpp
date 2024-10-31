#include <bits/stdc++.h>

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

std::string randombin(int n) {
  std::string res;
  for (int i = 0; i < n; i++) {
    res.push_back(rnd() % 2 + '0');
  }
  return res;
}

void makeTask(int n, int m) {
  std::cout << n << ' ' << m << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << randombin(m) << '\n';
  }
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  int T = 1;
  std::cout << T << '\n';
  while (T--) {
    makeTask(5, 5);
  }
}