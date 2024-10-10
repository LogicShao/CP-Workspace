#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PLL pair<LL, LL>

void s(int pos, vector<LL> &ans, vector<vector<PLL>> &w, vector<int> &p)
{
    if (p[pos] != 0)
        return;
    p[pos] = 1;
    for (auto [v, w_] : w[pos])
    {
        if (p[v] != 0)
            continue;
        ans[v] = ans[pos] + w_;
        s(v, ans, w, p);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<LL> ans(n, 0);
    vector<vector<PLL>> w(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w_;
        cin >> u >> v >> w_;
        u--; v--;
        w[u].push_back(make_pair(v, w_));
        w[v].push_back(make_pair(u, -w_));
    }
    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i)
        s(i, ans, w, p);

    for (auto i:ans)
        cout << i << ' ';
}

int main()
{
    solve();
    return 0;
}