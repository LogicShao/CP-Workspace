#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, in;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        cin >> in;
        ans += in;
    }
    cin >> in; ans = in - ans;
    cin >> in; ans = in - ans;
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