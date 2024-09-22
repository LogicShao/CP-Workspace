#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,a;
    long long ans=0;
    cin >> n;
    vector<int> l(n+10,0);
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        ans += (long long) (i - l[a]) * (n - i + 1);
        l[a] = i;
    }
    cout << ans;
}

int main()
{
    solve();
    return 0;
}