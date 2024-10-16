#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, r, a;
    int ans = 0, left = 0;
    cin >> n >> r;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        ans += a - a % 2;
        r -= a / 2;
        left += a % 2;
    }
    if (left > r)
        left = 2 * r - left;
    ans += left;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}