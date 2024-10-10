#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define LL long long
#define PLL pair<LL, LL>

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<PLL> seg(n);
    for (int i = 0; i < n; ++i)
        cin >> seg[i].first >> seg[i].second;
    sort(seg.begin(), seg.end());

    LL ans = 1;
    vector<LL> col(n, k);
    priority_queue<LL, vector<LL>, greater<LL>> c;
    for (int i = 0; i < n; ++i)
    {
        while (!c.empty() && c.top() < seg[i].first)
            c.pop();
        col[i] -= c.size();
        c.push(seg[i].second);
        // for (int j = i + 1; j < n && seg[j].first <= seg[i].second; ++j)
        //     col[j]--;
        ans = ( ans * col[i] ) % MOD;
    }
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}