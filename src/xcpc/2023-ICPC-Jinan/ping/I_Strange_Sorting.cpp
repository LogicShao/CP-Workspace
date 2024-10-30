#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    vector<pair<int, int>> ans;
    while( !is_sorted(a.begin(), a.end()) )
    {
        for (int l = 0; l < n; ++l)
            for (int r = n - 1; r > l; --r)
                if ( a[l] > a[r] )
                {
                    sort(a.begin() + l, a.begin() + r + 1);
                    ans.push_back({l + 1, r + 1});
                    l = n; r = 0;
                }
    }

    cout << ans.size() << '\n';
    for (auto [l, r]:ans)
        cout << l << " " << r << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}