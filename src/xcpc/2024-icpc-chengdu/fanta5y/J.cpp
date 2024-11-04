#include <bits/stdc++.h>

#define multi_test 1
#define DEBUG 0

using LL = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<LL, LL>;

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<LL> scores(m + 1);
  int now = -1;     // 表示当前关卡
  int rnk = 0;      // 表示第几个完成关卡
  std::set<int> st; // 表示那些玩家状态已经确定
  while (q--) {
    int op, id, x;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x;
      now = x;
      rnk = 0;
      st.clear();
    } else if (op == 2) {
      std::cin >> id >> x;
      if (st.count(id) or x != now)
        continue;
      scores[id] += m - rnk;
      st.insert(id);
      rnk++;
    } else {
      std::cin >> id >> x;
      if (st.count(id) or x != now)
        continue;
      st.insert(id);
    }
  }

  std::vector<PLL> data;
  for (int i = 1; i <= m; ++i) {
    data.emplace_back(scores[i], i);
  }

  std::sort(data.begin(), data.end(), [](const PLL &a, const PLL &b) {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
  });

  for (auto [score, id] : data) {
    std::cout << id << ' ' << score << '\n';
  }
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