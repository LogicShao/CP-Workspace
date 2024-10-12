#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> h(n, 0);
    vector<int> ans(n, 0);
    for (int i=0; i<n; ++i)
        cin >> h[i];

    priority_queue<int, vector<int>, greater<int>> a;
    for (int i=n-1; i>=0; --i)
    {
        ans[i] = a.size();
        while ( !a.empty() && a.top() < h[i] )
            a.pop();
        a.push(h[i]);
    }

    for ( auto i : ans )
        cout << i << " ";
}

int main()
{
    solve();
    return 0;
}