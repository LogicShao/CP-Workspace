#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int f[2100000];
const int mod = 1e9 + 7;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    f[fx] = fy;
    cnt--;
  }
}
void init(int n) {
  for (int i = 1; i <= n * 2 + 10; i++) {
    f[i] = i;
  }
  cnt = n * 2;
}
void work() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m + 10);
  init(n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      if (ch == '1') {
        a[j].push_back(i);
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    if (a[j].size()) {
      if (a[j].size() + a[m - j + 1].size() > 2) {
        cout << "0" << endl;
        return;
      }
      if (a[j].size() == 2) {
        merge(a[j][0], a[j][1] + n);
        merge(a[j][1], a[j][0] + n);
      } else if (a[m - j + 1].size() && j < m - j + 1) {
        merge(a[j][0], a[m - j + 1][0]);
        merge(a[m - j + 1][0] + n, a[j][0] + n);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) == find(i + n)) {
      cout << "0" << endl;
      return;
    }
  }
  long long ans = 1ll;
  for (int i = 1; i <= cnt / 2; i++) {
    ans = ans * 2ll % mod;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    work();
  }
}