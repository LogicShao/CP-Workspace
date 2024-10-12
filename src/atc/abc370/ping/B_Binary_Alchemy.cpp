#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n+1,vector<int>(n+1,0));

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=i; ++j)
            cin >> a[i][j];
    
    int ans = 1;
    for (int i=1; i<=n; ++i)
        ans = (ans >= i) ? a[ans][i] : a[i][ans];
    
    cout << ans;

    return 0;
}