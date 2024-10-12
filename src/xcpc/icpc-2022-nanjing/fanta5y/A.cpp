#include <bits/stdc++.h>

#define multi_test 1

template <typename T> void chkmax(T &a, const T &b) {
  if (a < b)
    a = b;
}

template <typename T> void chkmin(T &a, const T &b) {
  if (a > b)
    a = b;
}

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::string s;
  std::cin >> s;

  int N = 2 * n + 10, M = 2 * m + 10;
  auto g = std::vector(N, std::vector(M, 0));

  int up = 1, down = n, left = 1, right = m;
  {
    int u = 1, d = n, l = 1, r = m;
    int x = n, y = m; // 假设初始位置在(n, m)
    g[x][y] = 1;
    for (auto c : s) {
      if (c == 'U') {
        // 向下走
        u++, d++;
        x++;
        chkmax(up, u);
      } else if (c == 'D') {
        // 向上走
        u--, d--;
        x--;
        chkmin(down, d);
      } else if (c == 'L') {
        // 向右走
        l++, r++;
        y++;
        chkmax(left, l);
      } else {
        // 向左走
        l--, r--;
        y--;
        chkmin(right, r);
      }
      if (0 < x && x < N && 0 < y && y < M) {
        g[x][y] = 1;
      }
    }
  }

  if (up > down || left > right) {
    if (k) {
      std::cout << 0 << '\n';
    } else {
      std::cout << n * m << '\n';
    }
    return;
  }

  int alive = (down - up + 1) * (right - left + 1);
  // if (alive == k) {
  //   std::cout << n * m - k << '\n';
  //   return;
  // }

  // 求前缀和
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < M; j++) {
      g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
    }
  }

  // 表示这个区域内有多少已经被走过的区域
  auto count = [&](int x1, int y1, int x2, int y2) {
    return g[x2][y2] - g[x1 - 1][y2] - g[x2][y1 - 1] + g[x1 - 1][y1 - 1];
  };

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int deltax = n - i, deltay = m - j;
      int x1 = up + deltax, y1 = left + deltay;
      int x2 = down + deltax, y2 = right + deltay;

      if (alive - count(x1, y1, x2, y2) == k) {
        ans++;
      }
    }
  }

  std::cout << ans << '\n';
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