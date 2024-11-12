#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g;
vector<long long> deg;
void dfs(long long u, long long p, vector<long long> &w) {
  for (auto v : g[u]) {
    w[u] += (deg[v] == 2);
    if (v == p)
      continue;
    dfs(v, u, w);
    
  }
}
long long bfs(long long x, vector<long long> &w) {
  long long res = 0;
  queue<long long> q;
  q.push(x);
  while (!q.empty()) {
    long long u = q.front();
    res += w[u];
    q.pop();
    deg[u] = 0;
    for (auto v : g[u]) {
      if (deg[v] == 3) {
        q.push(v);
      }
    }
  }
  return res;
}
long long C(long long n, long long m) {
  if (n < m)
    return 0;
  long long res = 1;
  for (long long i = 1; i <= m; i++) {
    res = res * (n - i + 1) / i;
  }
  return res;
}
int main() {
  long long n;
  cin >> n;
  g.resize(n + 1);
  deg.resize(n + 1);
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);  
    deg[u]++;
    deg[v]++;
  }
  vector<long long> w(n + 1);
  dfs(1, 0, w);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (deg[i] == 3) {
      long long x = bfs(i, w);
      ans += C(x, 2);
    }
  }
  cout << ans << endl;
}