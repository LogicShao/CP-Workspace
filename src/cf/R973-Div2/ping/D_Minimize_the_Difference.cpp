#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; ++i)
        cin >> a[i];
    
    LL min_a = 1e18, max_a = - 1e18;
    LL sum_f = 0, sum_b = 0;
    for (LL i = 0; i < n; ++i)
    {
        sum_f += a[i]; 
        min_a = min(sum_f / (i + 1), min_a);
        
        sum_b += a[n - 1 - i];
        max_a = max((sum_b - 1) / (i + 1) + 1, max_a);
    }
    cout << (max_a - min_a) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}