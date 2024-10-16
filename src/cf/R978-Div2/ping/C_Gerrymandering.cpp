#include <bits/stdc++.h>
using namespace std;

#define set_max_a(a, b) a = max(a, b)
#define check(a, b, c) (a + b + c >= 2)

void solve()
{
    int n;
    cin >> n; getchar();
    vector<vector<int>> mp(2, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        char c = getchar();
        mp[0][i] = c == 'A';
    }
    getchar();
    for (int i = 0; i < n; ++i)
    {
        char c = getchar();
        mp[1][i] = c == 'A';
    }

    vector<vector<int>> dp(2, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i % 3 == 0)
        {
            set_max_a(dp[0][i + 3], dp[0][i] + check(mp[0][i], mp[0][i + 1], mp[0][i + 2])
                                             + check(mp[1][i], mp[1][i + 1], mp[1][i + 2]));
            set_max_a(dp[0][i + 1], dp[0][i] + check(mp[0][i], mp[0][i + 1], 
                                                     mp[1][i]));
            set_max_a(dp[1][i + 1], dp[0][i] + check(mp[0][i], 
                                                     mp[1][i], mp[1][i + 1]));
        }
        if (i % 3 == 1)
        {
            if (i < n - 3)
            {
                set_max_a(dp[0][i + 3], dp[0][i] + check(          mp[0][i + 1], mp[0][i + 2], mp[0][i + 3])
                                                 + check(mp[1][i], mp[1][i + 1], mp[1][i + 2]));
                set_max_a(dp[1][i + 3], dp[1][i] + check(mp[0][i], mp[0][i + 1], mp[0][i + 2])
                                                 + check(          mp[1][i + 1], mp[1][i + 2], mp[1][i + 3]));
            }
            set_max_a(dp[0][i + 2], dp[1][i] + check(mp[0][i], mp[0][i + 1], 
                                                               mp[1][i + 1]));
            set_max_a(dp[0][i + 2], dp[0][i] + check(          mp[0][i + 1], 
                                                     mp[1][i], mp[1][i + 1]));
        }
    }
    cout << dp[0][n] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}