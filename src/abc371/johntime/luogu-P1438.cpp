#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#include <bits/stdc++.h>

using LL = long long;

struct node
{
    int l, r;
    LL sum, add;
};

struct segmentTree
{
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define p tr[u]
#define pl tr[ls(u)]
#define pr tr[rs(u)]

    std::vector<node> tr;
    segmentTree(int n) : tr(n << 2) {}

    void pushup(int u)
    {
        p.sum = pl.sum + pr.sum;
    }

    void pushdown(int u)
    {
        if (p.add)
        {
            pl.sum += p.add * (pl.r - pl.l + 1);
            pr.sum += p.add * (pr.r - pr.l + 1);
            pl.add += p.add;
            pr.add += p.add;
            p.add = 0;
        }
    }

    void build(int u, int l, int r, std::vector<LL> &a)
    {
        p.l = l, p.r = r;
        if (l == r)
        {
            p.sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid, a);
        build(rs(u), mid + 1, r, a);
        pushup(u);
    }

    void add(int u, int l, int r, LL d)
    {
        if (p.l >= l && p.r <= r)
        {
            p.sum += d * (p.r - p.l + 1);
            p.add += d;
            return;
        }
        pushdown(u);
        int mid = (p.l + p.r) >> 1;
        if (l <= mid)
            add(ls(u), l, r, d);
        if (r > mid)
            add(rs(u), l, r, d);
        pushup(u);
    }

    LL query(int u, int l, int r)
    {
        if (p.l >= l && p.r <= r)
            return p.sum;
        pushdown(u);
        int mid = (p.l + p.r) >> 1;
        LL res = 0;
        if (l <= mid)
            res += query(ls(u), l, r);
        if (r > mid)
            res += query(rs(u), l, r);
        return res;
    }

#undef ls
#undef rs
#undef p
#undef pl
#undef pr
};

int main()
{
    // freopen("P1438_2.in","r",stdin);
    // freopen("P1438_2.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<LL> data(n + 1,0);
    for (int i = 1; i <= n; i++)
        cin >> data[i];
    for (int i = n - 1; i >= 1; i--)
        data[i + 1] = data[i + 1] - data[i];
    segmentTree tree(n);
    tree.build(1, 1, n, data);
    int opt;
    while (m--)
    {
        cin >> opt;
        if (opt == 1)
        {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            tree.add(1, l, l, k);
            if (l + 1 <= r)
                tree.add(1, l + 1, r, d);
            if (r + 1 <= n)
                tree.add(1, r + 1, r + 1, -k - (r - l) * d);
        }
        if (opt == 2){
            int q;
            cin>>q;
            cout<<tree.query(1,1,q)<<'\n';
        }
    }
}