#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 998244353;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> mp;
    vector<ll> s(n + 1), dp(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    ll sf = 1;//即dp[0]=1
    mp[0] = 1;//如果一开始出现s[i]=k的情况，需要减去这种情况
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = (dp[i] + sf - mp[s[i] - k]) % mod;
        sf =(sf+ dp[i])%mod;
        mp[s[i]] = (mp[s[i]]+dp[i])%mod;
    }
    cout << dp[n] << endl;
}