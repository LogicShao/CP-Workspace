// Wrong Answer （；´д｀）ゞ

#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    LL p, a, b;
    cin >> p >> a >> b;
    LL q, c, d;
    cin >> q >> c >> d;
    LL m, t;
    cin >> m >> t;

    // LL tot = 0;
    while (t > 0)
    {
        // tot++;

        // if ( t < a + c + b + d || m < p )
        //     break;
        // t -= b + d;
        // LL x = min( m / p, t / (a + c));
        // if ( x <= 0 )
        //     break;
        
        // t -= x * (a + c);
        // m += (q - p) * x; 

        if ( t < a + c + b + d || m < p )
            break;
        
        LL x = m / p;
        if ( x * ( a + c ) + b + d >= t)
        {
            x = (t - b - d) / (a + c);
            t -= x * (a + c);
            m += x * (q - p);
            continue;
        }
        
        LL nex = (p - (m - x * p)) / (q - p);
        if ( (p - (m % p)) % (q - p) != 0 )
            nex++;

        nex = min( t / (x * (a + c) + b + d), nex);
        
        // cout << t << " " << m << " " << nex << " ";
        t -= nex * (x * (a + c) + b + d);
        m += nex * ((q - p) * x); 
        // cout << t << " " << m << "\n";
    }
    // cout << m << " " << tot << endl;
    cout << m << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}