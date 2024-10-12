#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    LL p, q, a, b, c, d;
    LL m, t;

    cin >> p >> a >> b;
    cin >> q >> c >> d;
    cin >> m >> t;

    while (t > 0)
    {
        if ( t < a + c + b + d || m < p )
            break;
        
        LL x = m / p;
        if ( x * ( a + c ) + b + d >= t)
        {
            x = (t - b - d) / (a + c);
            t -= x * (a + c) + b + d;
            m += x * (q - p);
            continue;
        }
        
        LL nex = (p - (m - x * p)) / ((q - p) * x); // <- 看了一个小时才发现这里的 q-p 没加上乘x （；´д｀）ゞ
        if ( nex * ((q - p) * x) + m < x * p + p )
            nex++;

        if ( nex * (x * (a + c) + b + d) > t )
            nex = t / (x * (a + c) + b + d);
        
        t -= nex * (x * (a + c) + b + d);
        m += nex * ((q - p) * x); 
    }
    cout << m << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}