#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = "  " + s;
    int ans = 0;
    for (int i = 4; i <= n + 2; i++)
    {
        if (s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C')
        {
            ans++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        x++;
        if (s[x] == 'A' && s[x + 1] == 'B' && s[x + 2] == 'C')
        {
            ans--;
        }
        else if (s[x] == 'B' && s[x - 1] == 'A' && s[x + 1] == 'C')
        {
            ans--;
        }
        else if (s[x] == 'C' && s[x - 2] == 'A' && s[x - 1] == 'B')
        {
            ans--;
        }
        if (s[x + 1] == 'B' && s[x + 2] == 'C')
        {
            if (c == 'A')
                ans++;
        }
        if (s[x - 1] == 'A' && s[x + 1] == 'C')
        {
            if (c == 'B')
                ans++;
        }
        if (s[x - 2] == 'A' && s[x - 1] == 'B')
        {
            if (c == 'C')
                ans++;
        }
        s[x] = c;
        cout << ans << '\n';
    }
}