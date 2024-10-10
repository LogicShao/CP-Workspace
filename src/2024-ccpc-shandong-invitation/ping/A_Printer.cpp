#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL n, k;

bool check(LL time, vector<LL> &t, vector<LL> &l, vector<LL> &w)
{
    LL res = 0;
    for (int i = 0; i < n; ++i)
    {
        LL turn = time / ( t[i] * l[i] + w[i] );
        res += turn * l[i];
        LL left_t = time - turn * ( t[i] * l[i] + w[i] );

        if (left_t > t[i] * l[i])
            res += l[i];
        else
            res += left_t / t[i];

        if (res >= k)
            return 1;
    }
    return res >= k;
}

void solve()
{
    cin >> n >> k;
    vector<LL> t(n);
    vector<LL> l(n);
    vector<LL> w(n);

    for (int i = 0; i < n; ++i)
        cin >> t[i] >> l[i] >> w[i];

    LL lb = 0, rb = 2 * 1e18;
    while ( lb < rb )
    {
        LL mid = (lb + rb) / 2;
        if ( check( mid, t, l, w) )    
            rb = mid;
        else
            lb = mid + 1; 
    }
    cout << lb << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}