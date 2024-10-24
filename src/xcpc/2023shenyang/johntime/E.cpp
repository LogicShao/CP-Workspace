#include <bits/stdc++.h>
using namespace std;
constexpr int N = 110;
int main() {
  int X, Y, p, q;
  cin >> X >> Y >> p >> q;
  auto f = vector(N, vector(N, vector(2, -1)));
  auto bfs = [&](int x, int y) {
    queue<tuple<int, int, int>> que;
    que.emplace(x, y, 0);
    f[x][y][0] = 0;
    while (que.size()) {
      auto [x, y, k] = que.front();
      que.pop();
      if (k == 0) {
        for (int i = 1; i <= x; ++i) {
          for (int j = 1; j <= y; ++j) {
            int x1 = x - i, y1 = y - j;
            if (x1 + q < y1 and x1)
              continue;
            if (f[x][y][1] == -1) {
              f[x][y][1] = f[x][y][0] + 1;
              que.emplace(x, y, 1);
            }
          }
        }
      } else {
        for (int i = 1; i <= x; ++i) {
          for (int j = 1; j <= y; ++j) {
            int x1 = x + i, y1 = y + j;
            int x2 = X - x1, y2 = Y - y1;
            if (x2 + q < y2 and x2)
              continue;
            if (f[x2][y2][0] == -1) {
              f[x2][y2][0] = f[x][y][1] + 1;
              que.emplace(x2, y2, 0);
            }
          }
        }
      }
    }
  };
  bfs(X, Y);
  int ans = 1e9;
  for (int i = 1; i <= Y; ++i) {
    ans = min(ans, f[0][i][1]);
  }
  if (ans > 200)
    ans = -1;
  cout << ans << '\n';
}