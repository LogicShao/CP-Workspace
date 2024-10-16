#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    long long max_a = 0, sum = 0, ans;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        max_a = max(max_a, a[i]);
    }
    ans = max(max_a, (sum + x - 1) / x);
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