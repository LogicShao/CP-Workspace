#include <bits/stdc++.h>
const int N = 4e5 + 10;
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m;
    set<int> sx[n + 1], sy[m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sx[i].insert(j);
            sy[j].insert(i);
        }
    }

    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (sx[x].find(y) != sx[x].end())
        {
            sx[x].erase(y);
            sy[y].erase(x);
        }
        else
        {
            if (!sx[x].empty())
            {
                auto it = sx[x].upper_bound(y);
                if(it != sx[x].end())
                {
                    int y1 = *it;
                    sx[x].erase(y1);
                    sy[y1].erase(x);
                }
                if (!sx[x].empty())
                {
                    it = sx[x].upper_bound(y);
                    if (it != sx[x].begin())
                    {
                        it--;
                        int y2 = *it;
                        sx[x].erase(y2);
                        sy[y2].erase(x);
                    }
                }
            }
            if (!sy[y].empty())
            {
                auto it = sy[y].upper_bound(x);
                if(it != sy[y].end())
                {
                    int x1 = *it;
                    sy[y].erase(x1);
                    sx[x1].erase(y);
                }
                if (!sy[y].empty())
                {
                    it = sy[y].upper_bound(x);
                    if (it != sy[y].begin())
                    {
                        it--;
                        int x2 = *it;
                        sy[y].erase(x2);
                        sx[x2].erase(y);
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += sx[i].size();
    }
    cout << ans << endl;
}