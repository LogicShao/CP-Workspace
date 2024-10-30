#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    string s;
    cin >> s;
    for (auto &c:s)
        if ( c == '(' || c == ')' )
            c = '(';
        else if ( c == '[' || c == ']' )
            c = '[';
    
    int cnt = 0;
    for (int i = 0; i < s.length();)
    {
        int r = i;
        for (; r < s.length() && s[r] == s[i]; ++r);
        if (r - i >= 3)
        {
            cout << "No\n";
            return;
        }
        if (r - i == 2)
        {
            cnt++;
            if (cnt > 2)
            {
                cout << "No\n";
                return;
            }
        }
        i = r;
    }
    cout << "Yes\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}