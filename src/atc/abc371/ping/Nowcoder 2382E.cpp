#include <bits/stdc++.h>
using namespace std;

#define LL long long

struct node
{
    int l, r;
    LL sum;
    LL tag; // 表示等差数列首项

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
        if (p.tag != 0)
        {
            pl.tag = p.tag;
            pl.sum = ( 2 * pl.tag + pl.len() - 1) * pl.len() / 2;

            pr.tag = p.tag + pl.len();
            pr.sum = ( 2 * pr.tag + pr.len() - 1) * pr.len() / 2;

            p.tag = 0;
        }
    }

    void build(int u, int l, int r, vector<int> &a) 
    {
        p = {l, r, 0, 0};
        if (l == r) 
        {
            p.sum = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(ls, l, mid, a);
        build(rs, mid + 1, r, a);
        push_up(u);
    }

    void modify(int u, int l, int r, int k) // 把区间 [l,r] 改成以 k 为首项， 1 为公差的等差数列
    {
        if (l > r)
            return;
        if (l <= p.l && p.r <= r) 
        {
            p.tag = k + (p.l - l);
            p.sum = ( 2 * p.tag + p.len() - 1) * p.len() / 2;
            return;
        }
        push_down(u);

        int mid = (p.l + p.r) / 2;
        if (l <= mid)
            modify(ls, l, r, k);
        if (r > mid)
            modify(rs, l, r, k);
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
    int n, m, opt, l, r, k, d = 1;
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
            cin >> l >> r >> k;
            tr.modify(1, l, r, k);
        }
        else
        {
            cin >> l >> r;
            cout << tr.query(1, l, r) << '\n';
        }
    }
}

int main() 
{
    solve();
    return 0;
}