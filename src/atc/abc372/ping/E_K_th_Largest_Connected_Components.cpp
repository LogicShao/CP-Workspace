#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &f)
{
    return f[x]==x?x:f[x]=find(f[x], f);
}

void merge(vector<set<int>> &a, vector<int> &f, int u, int v)
{
    u=find(u, f);
    v=find(v, f);

    if (u == v)
        return;
    
    if( a[u].size() > a[v].size() )
        swap(u,v);
    
    f[u] = v;
    for( auto x:a[u] )
        a[v].emplace(x);
    a[u].clear();
}

void solve()
{
    int n, q;
    int opt, u, v, k;
    cin >> n >> q;

    vector<int> f(n + 1);
    vector<set<int>> a(n + 1);

    for(int i=1; i<=n; ++i)
        f[i] = i;
    for(int i=1; i<=n; ++i)
        a[i].insert(i);
    
    while ( q-- )
    {
        cin >> opt;
        if( opt == 1 )
        {
            cin >> u >> v;
            merge(a, f, u, v);
        }
        else
        {
            cin >> v >> k;
            v = find(v, f);
            if( a[v].size() < k )
                cout << "-1\n";
            else
                cout << *prev(a[v].end(),k) <<endl;
            
        }
    }
}

int main()
{
    solve();
    return 0;
}