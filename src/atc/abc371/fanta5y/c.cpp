#include <bits/stdc++.h>

#define multi_test 0

template <typename T> void chkmin(T &a, const T &b) {
  if (a > b)
    a = b;
}

void solve() {
  int n;
  std::cin >> n;

  int mg;
  std::cin >> mg;

  int N = n + 1;
  auto G = std::vector(N, std::vector(N, 0));
  auto H = G;
  auto A = G;

  while (mg--) {
    int a, b;
    std::cin >> a >> b;
    G[a][b] = G[b][a] = 1;
  }

  int mh;
  std::cin >> mh;

  while (mh--) {
    int a, b;
    std::cin >> a >> b;
    H[a][b] = H[b][a] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      std::cin >> A[i][j];
    }
  }

  auto ord = std::vector(n, 0);
  for (int i = 0; i < n; ++i)
    ord[i] = i + 1;

  int ans = 2e9;
  do {
    int cost = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        int u = ord[i - 1], v = ord[j - 1];
        if (u > v)
          std::swap(u, v);
        if (G[i][j] != H[u][v])
          cost += A[u][v];
      }
    }
    chkmin(ans, cost);
  } while (std::next_permutation(ord.begin(), ord.end()));

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