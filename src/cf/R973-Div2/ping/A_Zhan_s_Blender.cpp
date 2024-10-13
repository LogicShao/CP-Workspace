#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x, y;
    cin >> n >> x >> y;
    long long ans = n / min(x, y);
    if (n % min(x, y) != 0)
        ans++;
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