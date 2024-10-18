#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    long long high = 0,low = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        high += a[i];
        if (a[i] > low)
            low = a[i];
        low = max( (high + 1) / 2, low);
    }
    cout << low << " " << high << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}