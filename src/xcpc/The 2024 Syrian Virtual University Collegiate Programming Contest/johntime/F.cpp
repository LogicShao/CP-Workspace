#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = N << 1;
int h[N], e[M], ne[M], idx;
int fa[N], dep[N], siz[N], son[N], top[N], dfn[N], rnk[N], tot;
int s[N];
int n, m, s;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int p, int depth, int father)
{
    fa[p] = father;
    dep[p] = depth;
    siz[p] = 1;
    int mmax = -1;

    for (int i = h[p]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father)
            continue;
        dfs1(j, depth + 1, p);
        if (siz[j] > mmax)
        {
            mmax = siz[j];
            son[p] = j;
        }
        siz[p] += siz[j];
    }
}

void dfs2(int p, int tp)
{
    top[p] = tp;
    dfn[p] = ++tot;
    rnk[tot] = p;

    if (!son[p])
        return;

    for (int i = h[p]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != fa[p])
        {
            if (j != son[p])
                dfs2(j, j);
            else
                dfs2(j, tp);
        }
    }
}

int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] >= dep[top[y]])
            x = fa[top[x]];
        else
            y = fa[top[y]];
    }
    return dep[x] < dep[y] ? x : y;
}

void work()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(h, -1, (n + 10) * sizeof(int));
    idx = 0;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs1(1, 0, 0);
    dfs2(1, 1);
    for (int i = 1; i <= n; ++ i) {
        s[i] = s[i - 1] ^ a[rnk[i]];
    }
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
}
