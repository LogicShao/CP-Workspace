#include <bits/stdc++.h>
using namespace std;

bool check_side(int x1, int y1, int x2, int y2, int x_c, int y_c)
{
    int Vec_x = x2 - x1;
    int Vec_y = y2 - y1;
    int Vec_cx = x_c - x1;
    int Vec_cy = y_c - y1;

    return ( Vec_x * Vec_cy - Vec_y * Vec_cx < 0 );
    // > 0 : Left
    // < 0 : Right
}

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n + 2);
    vector<int> y(n + 2);
    for (int i=0; i<n; ++i)
        cin >> x[i] >> y[i];
    x[n] = x[0]; x[n + 1] = x[1];
    y[n] = y[0]; y[n + 1] = y[1];

    int ans = 0;
    for (int i=1; i<=n; ++i)
    {
        if ( check_side( x[i - 1], y[i - 1], x[i + 1], y[i + 1], x[i], y[i]) )
        {
            if (y[i] < y[i - 1] )
            {
                if (y[i + 1] > y[i])
                    ans++;
                else if (y[i + 1] == y[i])
                {
                    int j = i + 1;
                    for (; y[j] == y[i]; j = (j + 1) % n);
                    if ( y[j] > y[i])
                        ans++;
                }
            }
        }
    }    

    cout << ans;
}

int main()
{
   solve();
    return 0;
}