#include <bits/stdc++.h>

#define multi_test 0
#define DEBUG 1

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N = 110;

int f[N][N][2];

struct node {
  int x, y, k;
};

void solve() {
  int X, Y, P, Q;
  std::cin >> X >> Y >> P >> Q;
  
  memset(f, -1, sizeof(f));
  std::queue<node> q;
  q.emplace(X, Y, 0);
  f[X][Y][0] = 0;

  while (q.size()) {
    auto [x, y, k] = q.front();
    q.pop();

    if (x == 0) {
      std::cout << f[x][y][k] << '\n';
      return;
    }

    int z = X - x, t = Y - y;
    if (k == 0) {
      for (int dx = 0; dx <= std::min(P, x); ++dx) {
        for (int dy = 0; dy <= std::min(P - dx, y); ++dy) {
          int nx = x - dx, ny = y - dy;
          int nz = z + dx, nt = t + dy;
          if (nx == 0 or nx + Q >= ny) {
            if (f[nx][ny][1] == -1) {
              f[nx][ny][1] = f[x][y][0] + 1;
              q.emplace(nx, ny, 1);
            }
          }
        }
      }
    } else {
      for (int dz = 0; dz <= std::min(P, z); ++dz) {
        for (int dt = 0; dt <= std::min(P - dz, t); ++dt) {
          int nx = x + dz, ny = y + dt;
          int nz = z - dz, nt = t - dt;
          if (nz == 0 or nz + Q >= nt) {
            if (f[nx][ny][0] == -1) {
              f[nx][ny][0] = f[x][y][1] + 1;
              q.emplace(nx, ny, 0);
            }
          }
        }
      }
    }
  }

  std::cout << -1 << '\n';
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