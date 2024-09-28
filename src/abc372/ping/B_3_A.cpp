#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int M, tot = 0;
    cin >> M;
    vector<int> ans(20, 0);
    for (int i = 0; M; M /= 3, ++i)
    {
        tot += M % 3;
        ans[i]+=M % 3;
    }
    cout << tot << '\n';
    for (int i = 0; i < 11; ++i)
        for (int j = 0; j < ans[i]; ++j)
            cout << i << " ";
}

int main()
{
    solve();
    return 0;
}