#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    LL la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;
    LL l = la + lb;
    LL r = ra + rb;

    LL ans = l % 10;
    do
    {
        if ((r - l) >= 10)
            ans = 9;
        else if (l % 10 > r % 10)
            ans = 9;
        else
            ans = max(ans, r % 10);
        l /= 10;
        r /= 10;
    } while (l > 0 || r > 0);
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