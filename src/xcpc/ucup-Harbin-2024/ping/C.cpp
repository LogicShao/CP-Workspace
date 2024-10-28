#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    int n;
    cin >> n;
    
    int d, x, now_d;
    map<char, int> d_k;
    d_k['N'] = 0;
    d_k['E'] = 1;
    d_k['S'] = 2;
    d_k['W'] = 3;

    getchar();
    vector<pair<char, int>> ans;
    char ans_init_d;
    for (int i = 1; i <= n; ++i)
    {
        char in_c = getchar();
        d = d_k[ in_c ];
        cin >> x;
        getchar();

        if (i == 1)
        {
            now_d = d;
            ans_init_d = in_c;
        }
        else
        {
            int turn = (d - now_d + 4) % 4;
            if (turn == 1)
                ans.push_back({'R',0});
            else
                ans.push_back({'L',0});
        }
        ans.push_back({'Z',x});
        now_d = d;
    }
    cout << ans.size() << " " << ans_init_d << '\n';
    for (auto [x,y]:ans)
    {
        if (x == 'Z')
            cout << "Z " << y << '\n';
        else
            cout << x << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}