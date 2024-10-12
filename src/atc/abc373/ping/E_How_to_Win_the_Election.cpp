#include <bits/stdc++.h>
using namespace std;

#define LL long long

bool check(LL x, int pos, vector<LL> &a, vector<LL> &b, vector<LL> &sum, LL tot, int m, int n)
{
    int p = upper_bound(b.begin(), b.end(), a[pos] + x) - b.begin();
    int cnt = n - p;
    if (cnt >= m)
        return 0;

    LL left = tot - x;
    LL need = (m - cnt) * (a[pos] + x + 1);
    need -= sum[p] - sum[n - m];
    if ( a[pos] >= b[n - m] )
        need += a[pos] - b[n - m - 1];
    if (need > left)
        return 1;
    return 0;
}

int main()
{
    LL n, m, k, tot = 0;
    cin >> n >> m >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        tot += a[i];
    }
    vector<LL> b(n);
    b = a;
    sort(b.begin(), b.end());
    tot = k - tot;

    vector<LL> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + b[i - 1];
    
    LL ans;
    for (int i = 0; i < n; ++i)
    {
        if ( n == m )   // <- 针对 02_hand_11 测试点
            ans = 0;
        else if (a[i] + tot < b[n - m])
            ans = -1;
        else
        {
            LL l = 0, r = tot;
            while ( l < r )
            {
                LL mid = (l + r) / 2;
                if (check(mid, i, a, b, sum, tot, m, n))
                    r = mid;
                else
                    l = mid + 1;
            }
            ans = l;
        }
        cout << ans << ' ';
    }
    return 0;
}