#include <bits/stdc++.h>
using namespace std;

// bool vis[ 2010 ][ 2010 ];
// int a[ 2010 ][ 2010 ];

#define D 100

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;
    int len = s.length();

    // 边界调整
    int up__ = 1, down = n, left = 1, righ = m;
    int Up = 1, Do = n, Le = 1, Ri = m;
    for (int i = 0; i < len; ++i)
    {
        switch ( s[i] )
        {
            case 'U': up__++; down++; break;
            case 'D': up__--; down--; break;
            case 'L': left++; righ++; break;
            case 'R': left--; righ--; break;
            default: return;
        }
        
        Le = max(Le, left);
        Ri = min(Ri, righ);
        Up = max(Up, up__);
        Do = min(Do, down);
    }
    up__ = Up; left = Le; down = Do; righ = Ri;
    // cout << up__ << " " << left << " " << down << " " << righ << endl;

	bool has = 1;
	if ( down < up__ || righ < left )
		has = 0;
    int drop = (down - up__ + 1) * (righ - left + 1) - k;
    if ( has == 0 || drop < 0 )
    {
        if ( k == 0 )   cout << (n * m) << '\n';
        else            cout << "0\n";
        return;
    }

    // 利用 差分+二维前缀和 模拟一堆袋鼠移动
    // vis 判断是否为重复走过的路

    // memset(a, 0, sizeof(a));
    // memset(vis, 0, sizeof(vis));
    vector<vector<bool>> vis(D + n + 10, vector<bool>(D + m + 10, 0));
    vector<vector<int>> a(D + n + 10, vector<int>(D + m + 10, 0));

    int u = up__ + D, d = down + D, l = left + D, r = righ + D; // 袋鼠区域边界
    
    vis[u][l] = 1;
    a[u][l]++;
    a[d + 1][l]--;
    a[u][r + 1]--;
    a[d + 1][r + 1]++;
    
    for (int i = 0; i < len; ++i)
    {
        switch ( s[i] )
        {
            case 'U': u--; d--; break;
            case 'D': u++; d++; break;
            case 'L': l--; r--; break;
            case 'R': l++; r++; break;
            default: return;
        }
        
        if (!vis[u][l])
        {
            vis[u][l] = 1;
            a[u][l]++;
            a[d + 1][l]--;
            a[u][r + 1]--;
            a[d + 1][r + 1]++;
            // 1 -1
            // -1 1
        }
    }

    // for (int i = 0; i <= n; ++i)
    //     for (int j = 0; j <= m; ++j)
    //         cout << a[i][j] << " \n"[j==m];
    
    // cout << endl;

    
    // for (int i = 0; i <= n; ++i)
    //     for (int j = 0; j <= m; ++j)
    //         cout << vis[i][j] << " \n"[j==m];

    // cout << endl;

    // 前缀和
    for (int i = 1 + D; i <= n + D; ++i)
        for (int j = 1 + D; j <= m + D; ++j)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

    // 计算ans
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            // cout << a[i][j] << " \n"[j==m];
            if ( a[i + D][j + D] == drop )
                ans++;
        }

    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}