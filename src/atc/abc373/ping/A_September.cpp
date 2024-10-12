#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    string s;
    for (int i = 1; i <= 12; ++i)
    {
        cin >> s;
        ans += (s.length() == i);
    }
    cout << ans;
    return 0;
}