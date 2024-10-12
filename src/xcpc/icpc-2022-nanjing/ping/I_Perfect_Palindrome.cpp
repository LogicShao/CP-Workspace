#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<pair<int, int>> count(30);
    for (int i='a'; i<='z'; ++i)
        count[i - 'a'].second = i;
    for (auto c:s)
        count[c - 'a'].first++;
    sort(count.begin(), count.end(), greater<pair<int, int>>() );
    cout << (s.length() - count[0].first) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}