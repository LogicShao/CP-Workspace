#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#include <bits/stdc++.h>

using LL = long long;

struct node
{
    int l, r;
    LL sum, st; // sum表示区间和，st表示区间的第一个数
    int len() const
    {
        return r - l + 1;
    }
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
        if (p.st)
        {
            pl.st = p.st;
            pl.sum = (2ll * pl.st + pl.len() - 1) * pl.len() / 2;
            pr.st = p.st + pl.len();
            pr.sum = (2ll * pr.st + pr.len() - 1) * pr.len() / 2;
            p.st=0;
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
            p.st += d;
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
    void modify(int u, int l, int r, LL d) // 将区间l到r修改为d为首项，1为公差的等差数列
    {
        if (p.l >= l && p.r <= r)
        {
            p.st = d + p.l - l; // 前面已经有p.l-l项
            p.sum = (2ll * p.st + p.len() - 1) * p.len() / 2;
            return;
        }
        pushdown(u);
        int mid=(p.l+p.r)>>1;
        if(l<=mid){
            modify(ls(u),l,r,d);
        }
        if(r>mid){
            modify(rs(u),l,r,d);
        }
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
    int n,m;
    cin>>n>>m;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    segmentTree tree(n);
    tree.build(1,1,n,a);
    while(m--){
        int opt;
        cin>>opt;
        if(opt==1){
            int l,r,k;
            cin>>l>>r>>k;
            tree.modify(1,l,r,k);
        }
        if(opt==2){
            int l,r;
            cin>>l>>r;
            cout<<tree.query(1,l,r)<<'\n';
        }
    }
}