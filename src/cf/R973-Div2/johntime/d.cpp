#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void work()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll sum1 = 0, sum2 = 0, ans1 = 1e18, ans2 = -1e18;
    for (int i = 1; i <= n; i++)
        sum1 += a[i], ans1 = min(ans1, sum1 / i);
    for (int i = n; i >= 1; i--)
        sum2 += a[i], ans2 = max(ans2, ((sum2 - 1) / (n - i + 1) + 1));
    cout << ans2 - ans1 << '\n';
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
}