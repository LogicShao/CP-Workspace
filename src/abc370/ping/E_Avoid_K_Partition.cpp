#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define LL long long

void solve()
{
    int n; LL k;
    cin >> n >> k;

    vector<LL> ans(n+1, 0);
    // 利用 ans[n] 表示第 1 位到第 n 位的序列有几个合法分裂方案
    // ans[n] 可表示为 sum_{i=0}^{n-1}{ ans[i] * 从 i+1 位到 n 位的子序列之和是否不等于 k }
    // 上式可化简为： 从 0 到 n-1 的所有 ans[i] 之和 - 所有之后子序列的和等于 k 的 ans[i] 之和
    // 前者可用 tot 计算
    LL tot;
    // 后者可用 map 存放每个前缀和对应的 ans 来计算
    map<LL, LL> s;
    LL sum = 0;

    // 处理第 0 位的情况
    s[0] = 1;
    tot = 1;

    LL a;
    for (int i=1; i<=n; ++i)
    {
        cin >> a;
        sum += a;

        ans[i] = (tot - s[ sum - k ] + MOD) % MOD;
        s[sum] = (s[sum] + ans[i]) % MOD;
        tot = (tot + ans[i] + MOD) % MOD;
    }

    cout << ans[n];
}

int main()
{
    solve();
    return 0;
}