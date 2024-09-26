#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e10

int gcd(int a,int b)
{
    return (b == 0) ? a : gcd(b, a%b);
}

void solve()
{
    int n;
    int tot_atk = 1, tot_m = 1;
    cin >> n;
    vector<int> a(n);
    int count = 0;
    for (int i=0; i<n; ++i)
    {
        cin >> a[i];
    }
    for (int i=0; i<n; ++i)
    {
        if (a[i]==-1)
        {
            tot_m--;
            if (tot_m <= 0)
            {
                if (count > 0)
                {
                    tot_m++;
                    tot_atk++;
                    count--; tot_m++;
                }
                else
                    tot_m = -INF;
            }
        }
        if (a[i]==1)
        {
            tot_atk++;
            tot_m++;
        }
        if (a[i] == 0)
        {
            if (tot_m > 1)
            {
                count++;
                tot_m--;
            }
            else
            {
                tot_m++;
                tot_atk++;
            }
        }
    }
    if (tot_m <= 0)
    {
        cout << "-1\n";
        return;
    }

    int g = gcd(tot_atk, tot_m);
    tot_atk /= g;
    tot_m /= g;
    cout << tot_atk << " " << tot_m << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}