#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;

    vector<string> ans;
    while ( s!=t )
    {
        int change = -1;
        for (int i=0; i<s.length(); ++i)
            if (s[i] > t[i])
            {
                change = i;
                break;
            }
        if (change == -1)
            for (change = s.length() - 1; s[change]==t[change]; --change);
        s[change] = t[change];
        ans.push_back(s);
    }

    cout << ans.size() << '\n';
    for (auto o:ans)
        cout << o << '\n';
}

int main()
{
    solve();
    return 0;
}