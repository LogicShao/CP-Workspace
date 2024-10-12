#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,a,b;
    cin >> n;
    vector<vector<int>> g(n+1,vector<int>(n+1,0));
    vector<vector<int>> h(n+1,vector<int>(n+1,0));
    vector<vector<int>> price(n+1,vector<int>(n+1,0));
    cin >> m;
    for (int i=0; i<m; ++i)
    {
        cin >> a >> b;
        g[a][b]=g[b][a]=1;
    }

    cin >> m;
    for (int i=0; i<m; ++i)
    {
        cin >> a >> b;
        h[a][b]=h[b][a]=1;
    }

    for (int i=1; i<=n-1; ++i)
    {
        for (int j=i+1; j<=n; ++j)
        {
            cin >> price[i][j];
            price[j][i]=price[i][j];
        }
    }

    long long ans=1e10,c=0;
    vector<int> p(n); 
    for (int i=0; i<n; ++i) p[i]=i+1;
    do{
        c=0;
        for (int i=1; i<n; ++i)
        {
            for (int j=i+1; j<=n; ++j)
            {
                if (h[i][j]^g[p[i-1]][p[j-1]])
                    c+=price[i][j];
            }
        }
        ans=c<ans?c:ans;
    }while (next_permutation(p.begin(),p.end()));
    cout << ans;
}

int main()
{
    int t = 1;
    while (t--)
        solve();
    return 0;
}