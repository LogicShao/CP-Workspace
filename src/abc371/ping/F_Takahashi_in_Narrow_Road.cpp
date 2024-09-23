#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF (LL)1e18

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

    int N;

    SegmentTree(int n) : tr(n * 4 + 10) { N=n; }

    void push_up(int u) 
    {
        p.sum = pl.sum + pr.sum;
    }

    void push_down(int u) 
    {
        if (p.tag != INF)
        {
            pl.tag = p.tag;
            pl.sum = ( 2 * pl.tag + pl.len() - 1) * pl.len() / 2;

            pr.tag = p.tag + pl.len();
            pr.sum = ( 2 * pr.tag + pr.len() - 1) * pr.len() / 2;

            p.tag = INF;
        }
    }

    void build(int u, int l, int r, vector<int> &a) 
    {
        p = {l, r, 0, INF};
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
        if (l <= 0)
            return -INF;
        if (r > N)
            return INF;
        
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
    LL n, q, t, g;
    LL ans = 0;

    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; ++i)
        cin >> a[i];

    SegmentTree tr(n);
    tr.build(1, 1, n, a);

    cin >> q;
    while (q--) 
    {
        cin >> t >> g;

        // 每次移动，都相当于把一定区间内所有人的位置改成一个等差数列
        // 二分查找区间边界
        int s_l = t, s_r = t, s_mid, s_goal;
        if (tr.query(1, t, t) >= g) 
            s_l = 1;
        else
            s_r = n + 1;
        
        while (s_l < s_r) 
        {
            s_mid = (s_l + s_r) / 2;
            s_goal = (s_mid <= t) ? (g - (t - s_mid)) : (g + (s_mid - t));

            int mid_q = tr.query(1, s_mid, s_mid);
            if (mid_q < s_goal)
                s_l = s_mid + 1;
            else
                s_r = s_mid;
        }

        LL re = 0;
        if (tr.query(1, t, t) >= g)
        {
            re = tr.query(1, s_l, t) - (g * 2 - (t - s_l)) * (t - s_l + 1) / 2;
            tr.modify(1, s_l, t, g - (t - s_l));
        }
        else
        {
            s_l--;
            re = (g * 2 + (s_l - t)) * (s_l - t + 1) / 2 - tr.query(1, t, s_l);
            tr.modify(1, t, s_l, g);
        }
        ans += re;
        
        // for (int i=1; i<=n; ++i)
        //     cout << tr.query(1, i, i) << " ";
        // cout << re << endl;
    }

    cout << ans;
}

int main() 
{
    solve();
    return 0;
}