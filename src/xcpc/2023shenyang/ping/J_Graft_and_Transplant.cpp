#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, u, v, c;
    cin >> n;
    c = n - 1;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> u >> v;
        a[u]++;
        a[v]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] <= 1)
            c--;
    }
    if ( c < 0 )
        c = 0;
    if ( c % 2 == 0 )
        cout << "Bob";
    else
        cout << "Alice";
}

int main()
{
    solve();
    return 0;
}