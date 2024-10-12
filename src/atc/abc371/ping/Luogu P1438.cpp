#include <bits/stdc++.h>
using namespace std;

#define LL long long

struct node
{
    int l, r;
    LL sum;
    LL tag; // 表示未向下处理的加项

    int len() { return r - l + 1; }
};

struct SegmentTree 
{
#define ls (u * 2)
#define rs (u * 2 + 1)
#define p tr[u]
#define pl tr[ls]
#define pr tr[rs]

    vector<node> tr;

    SegmentTree(int n) : tr(n * 4 + 10) {}

    void push_up(int u) 
    {
        p.sum = pl.sum + pr.sum;
    }

    void push_down(int u) 
    {
        int mid = (p.l + p.r) / 2;

        pl.tag += p.tag;
        pl.sum += p.tag * (mid - p.l + 1);

        pr.tag += p.tag;
        pr.sum += p.tag * (p.r - mid);

        p.tag = 0;
    }

    void build(int u, int l, int r, vector<int> &a) 
    {
        p = {l, r, 0, 0};
        if (l == r) 
        {
            p.sum = a[l] - a[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build(ls, l, mid, a);
        build(rs, mid + 1, r, a);
        push_up(u);
    }

    void add(int u, int l, int r, int k) 
    {
        if (l > r)
            return;
        if (l <= p.l && p.r <= r) 
        {
            p.tag += k;
            p.sum += (p.r - p.l + 1) * k;
            return;
        }
        push_down(u);

        int mid = (p.l + p.r) / 2;
        if (l <= mid)
            add(ls, l, r, k);
        if (r > mid)
            add(rs, l, r, k);
        push_up(u);
    }

    LL query(int u, int l, int r) 
    {
        if (l > r)
            return 0;
        if (l <= p.l && p.r <= r)
            return p.sum;
        
        push_down(u);

        int mid = (p.l + p.r) / 2;
        LL ret = 0;
        if (l <= mid)
            ret += query(ls, l, r);
        if (r > mid)
            ret += query(rs, l, r);
        return ret;
    }

#undef pr
#undef pl
#undef p
#undef rs
#undef ls
};

void solve() 
{
    int n, m, opt, l, r, k, d, p;
    cin >> n >> m;
    
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; ++i)
        cin >> a[i];

    SegmentTree tr(n+1);
    tr.build(1, 1, n+1, a);

    while (m--)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> l >> r >> k >> d;
            tr.add(1, l, l, k);
            tr.add(1, l + 1, r, d);
            tr.add(1, r + 1, r + 1, -(k + (r - l) * d) );
        }
        else
        {
            cin >> p;
            cout << tr.query(1, 1, p) << '\n';
        }
    }
}

int main() 
{
    solve();
    return 0;
}