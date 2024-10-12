#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define dis(x, y) ((x < y) ? (y - x) : (y - x + n))

void solve()
{
    int n, m, k;
    int x, y;
    cin >> n >> m >> k;
    
    vector<vector<int>> e(n + 10);
    // 记录添加了边的点的编号
    vector<int> pos(2, 1);
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        e[y].push_back(x);

        pos.push_back(x);
        pos.push_back(y);
    }
    sort(pos.begin() + 1, pos.end());
    int cnt = unique(pos.begin() + 1, pos.end()) - pos.begin() - 1;

    // 标记各点编号在 pos 中的位置
    vector<int> locate(n + 10);
    for(int i = 1; i <= cnt; ++i) 
        locate[pos[i]] = i;

    vector<vector<int>> dp(cnt + 10, vector<int>(k + 10, 0));

    // 仅考虑添加了边的点
    // dp[x][y] 表示 到达点 pos[x] 用了 y 步 的总路径数
    dp[1][0] = 1;   // 对于其他 y = 0 , 默认赋值 0
    for(int i = 1; i <= k; ++i) 
    {
        for(int j = 1; j <= cnt; ++j) 
        {
            // 考虑相邻点之间固有的连接
            int pre = (j - 1 + cnt - 1) % cnt + 1;
            if(i - dis(pos[pre], pos[j]) >= 0)
                dp[j][i] = dp[pre][ i - dis(pos[pre], pos[j]) ];

            // 考虑添加的连接
            for(auto k : e[ pos[j] ])
                dp[j][i] = (dp[j][i] + dp[ locate[k] ][ i - 1 ]) % MOD;
        }
    }

    int ans = 0;
    // 考虑其他点
    for(int i = 1; i <= cnt; ++i) 
    {
        int nex = (i + 1 + cnt - 1) % cnt + 1;
        for(int p = k; p >= k - dis(pos[i], pos[nex]) + 1; --p)
        // 相当于遍历 点pos[i] 到 点pos[nex]（不含） 之间的所有点 
            ans = (ans + dp[i][p]) % MOD;
            // 即对于所有的点，求和 到达它们用了 k 步的路径数
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}