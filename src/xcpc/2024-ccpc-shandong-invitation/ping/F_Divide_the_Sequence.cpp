#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n + 1);
    vector<LL> sum(n + 1, 0);
    priority_queue<LL, vector<LL>, greater<LL>> flag;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        if ( i != n )
            flag.push( sum[i] );
    }
    LL s = sum[n];
    cout << s << " ";
    while ( !flag.empty() )
    {
        s += (sum[n] - flag.top());
        flag.pop();
        cout << s << ' ';
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}