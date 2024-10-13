#include <bits/stdc++.h>
using namespace std;

bool query(string s)
{
    cout << "? " << s << '\n';
    fflush(stdout);
    int res;
    cin >> res;
    if (res == -1)
        exit(0);
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string ans;
    int ri = 1;
    while (ans.size() < n)
    {
        if (ri)
        {
            if (query( ans + "0" ))
                ans = ans + "0";
            else
                if (query(ans + "1" ))
                    ans = ans + "1";
                else
                    ri = 0;
        }
        else
        {
            if (query( "0" + ans ))
                ans = "0" + ans;
            else
                ans = "1" + ans;
        }
    }
    cout << "! " << ans << '\n';
    fflush(stdout);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}