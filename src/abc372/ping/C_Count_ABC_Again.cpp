#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;

    string comp = "ABC"; int flag = 0, tot = 0;
    for (int i = 0; i < n; ++i)
    {
        if ( s[i] != comp[flag] )
            flag = 0;
        if ( s[i] == comp[flag] )
        {
            flag++;
            if ( flag == 3 )
            {
                tot++;
                flag = 0;
            }
        }
        else flag = 0;
    }
    
    int x; char c;
    while (q--)
    {
        cin >> x >> c;
        if (c == 'A' && s[x - 1] != 'A' && x <= n-2 
            && s[x] == 'B' && s[x + 1] == 'C' )
                tot++;
        if (c == 'B' && s[x - 1] != 'B' && x <= n-1 && x >= 2
            && s[x - 2] == 'A' && s[x] == 'C' )
                tot++;
        if (c == 'C' && s[x - 1] != 'C' && x >= 3 
            && s[x - 3] == 'A' && s[x - 2] == 'B' )
                tot++;
        
        if (c != 'A' && s[x - 1] == 'A' && x <= n-2
            && s[x] == 'B' && s[x + 1] == 'C' )
                tot--;
        if (c != 'B' && s[x - 1] == 'B' && x <= n-1 && x >= 2
            && s[x - 2] == 'A' && s[x] == 'C' )
                tot--;
        if (c != 'C' && s[x - 1] == 'C' && x >= 3
            && s[x - 3] == 'A' && s[x - 2] == 'B' )
                tot--;

        s[x - 1] = c;
        cout << tot << endl;
    }
}

int main()
{
    solve();
    return 0;
}