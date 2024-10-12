#include <bits/stdc++.h>
using namespace std;

#define LL long long

struct edge
{
    LL u, v, w;
};

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int findroot(int x, vector<LL> &fa)
{
    return ( fa[x] == x ) ? x : ( fa[x] = findroot(fa[x], fa) );
}

void merge(int a, int b, vector<LL> &fa)
{
    a = findroot(a, fa);
    b = findroot(b, fa);
    fa[a] = b;
}

void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<LL>> b(n, vector<LL>(n));
    vector<LL> min_w(n, 1e6 + 10);
    vector<edge> e;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> b[i][j];
            min_w[j] = min(min_w[j], b[i][j]);
            if ( j <= i )
                e.push_back({i, j, b[i][j]});
        }
    sort(e.begin(), e.end(), cmp);

    vector<LL> fa(n);
    for (int i = 0; i < n; ++i)
        fa[i] = i;

    LL tot = 0, ans = 0;
    for (int i = 0; i < e.size(); ++i)
    {
        int xr = findroot(e[i].u, fa), yr = findroot(e[i].v, fa);
        if ( xr == yr )
            continue;
        merge(xr, yr, fa);
        tot++;
        ans += e[i].w;
        if (tot == n)
            break;
    }

    for (int i = 0; i < n; ++i)
        ans += (a[i] - 1) * min_w[i];
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