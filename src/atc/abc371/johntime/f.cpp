#include <bits/stdc++.h>
using namespace std;
using LL = long long;

using ll = long long;

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
            p.st = 0;
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
        int mid = (p.l + p.r) >> 1;
        if (l <= mid)
        {
            modify(ls(u), l, r, d);
        }
        if (r > mid)
        {
            modify(rs(u), l, r, d);
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
    int n;
    cin >> n;
    vector<LL> x(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    segmentTree tree(n);
    tree.build(1, 1, n, x);
    int m;
    cin >> m;
    ll ans = 0;
    while (m--)
    {
        int t, g;
        cin >> t >> g;
        if (tree.query(1, t, t) >= g) // t的位置在g的右边
        {
            int lb = 1, ub = t;
            while (lb < ub)
            {
                int mid = (lb + ub) >> 1;
                int len = t - mid + 1;//动态分析当前的长度
                int L = g - len + 1, R = g;//确定目标的区间
                if (tree.query(1, mid, mid) >= L)//如果当前查询的值在目标区间的右边
                {
                    ub = mid;
                }
                else
                {
                    lb = mid + 1;
                }
            }
            int len = t - lb + 1;
            ll cost = tree.query(1, lb, t) - ((ll)g * 2 - len + 1) * len / 2;//当前的代价等于移动前的位置减去移动后的位置所形成的等差数列
            ans += cost;
            tree.modify(1, lb, t, g - len + 1);//区间赋值为等差数列
        }
        else
        { // t的位置在g的左边
            int lb = t, ub = n;
            while (lb < ub)
            {
                int mid = (lb + ub + 1) >> 1;
                int len = mid - t + 1;
                int L = g - len + 1, R = g;
                if (tree.query(1, mid, mid) <= R)
                {
                    lb = mid;
                }
                else
                {
                    ub = mid - 1;
                }
            }
            int len = ub - t + 1;
            ll cost = ((ll)g * 2 + len  - 1) * len / 2 - tree.query(1, t, ub);
            ans += cost;
            tree.modify(1, t, ub, g);
        }
    }
    cout << ans << endl;
}