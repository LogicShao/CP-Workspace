#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> a;
ll n, k, m, c, d;
bool check(ll x)
{
    ll w = 0;
    vector<ll> b(n + 10, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] >= x)
            w++;
    }
    if (w >= k)
    {
        return true;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] >= x)
        {
            continue;
        }
        ll l = max(1ll, i - m + 1);
        if (a[i] + c + (i - l) * d < x)
        {
            continue;
        }
        b[l]++;
        ll y;
        if (d == 0)
            y = 0;
        if (x - a[i] - c <= 0)//0%d也会出现错误
            y = 0;
        else
        {
            if ((x - a[i] - c) % d == 0)
                y = (x - a[i] - c) / d;
            else
                y = (x - a[i] - c) / d + 1;
        }
        ll r = i - y;
        b[r + 1]--;
    }
    ll maxp = 0;
    for (ll i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        maxp = max(maxp, b[i]);
    }
    return maxp + w >= k;
}
int main()
{

    cin >> n >> k >> m >> c >> d;
    a.resize(n + 10);
    ll maxa = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    ll l = 0, r = 1e16;
  while (l < r) {
    ll mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
    cout << l << endl;
}