#include <bits/stdc++.h>
using namespace std;

void destroy_wall(int h, int w, vector<set<int>> &walls_h, vector<set<int>> &walls_w, int &ans) 
{
    // 删除第 h 行，第 w 列的墙
    walls_h[h].erase( walls_h[h].find(w) );
    walls_w[w].erase( walls_w[w].find(h) );
    ans--;
}

void solve()
{
    int h, w;
    cin >> h >> w;
    int ans = h * w;

    // 利用set模拟各行各列的墙
    vector<set<int>> walls_h(h + 1);    // 各行
    vector<set<int>> walls_w(w + 1);    // 各列

    for (int i=1; i<=h; ++i)
        for (int j=1; j<=w; ++j)
            walls_h[i].insert(j);
    for (int i=1; i<=w; ++i)
        for (int j=1; j<=h; ++j)
            walls_w[i].insert(j);

    int q, r, c;
    cin >> q;
    while ( q-- )
    {
        cin >> r >> c;

        // 无论如何，先上下看（判断行）
        // f_h 表示当前行内，往右看（包含自己）找到的第一个墙的列位置
        auto f_h = walls_h[r].lower_bound(c);
        if ( *f_h == c )    // 若墙存在
            destroy_wall(r, c, walls_h, walls_w, ans);
        else
        {
            // 上下看
            if (f_h != walls_h[r].begin())
                destroy_wall( r, *(prev(f_h)), walls_h, walls_w, ans );
            if (f_h != walls_h[r].end())
                destroy_wall( r, *f_h, walls_h, walls_w, ans );
            
            // 左右看
            auto f_w = walls_w[c].lower_bound(r);
            if (f_w != walls_w[c].begin())
                destroy_wall( *(prev(f_w)), c, walls_h, walls_w, ans );
            if (f_w != walls_w[c].end())
                destroy_wall( *f_w, c, walls_h, walls_w, ans );
        }
    }

    cout << ans;
}

int main()
{
    solve();
    return 0;
}