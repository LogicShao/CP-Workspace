#include <bits/stdc++.h>
using namespace std;

#define PLL pair<long long, long long>

void solve()
{
    int n;
    cin >> n;

    vector<PLL> v(n);
    for (auto &i:v)
        cin >> i.first;
    for (auto &i:v)
        cin >> i.second;
    
    sort(v.begin(), v.end());
    vector<PLL> s(n+2);
    s[0] = PLL(-1e9-10, 0);
    for (int i=0; i<n; ++i)
    {
        s[i+1].first = v[i].first;
        s[i+1].second = s[i].second + v[i].second;
    }
    s[n+1] = PLL(1e9+10, s[n].second);

    int q,l,r;
    cin >> q;
    auto compare = [](const PLL &x, const PLL &y) { return x.first < y.first; };
    while (q--)
    {
        cin >> l >> r;
        auto le = lower_bound(s.begin(), s.end(), PLL(l, 0), compare); le--;
        auto ri = upper_bound(s.begin(), s.end(), PLL(r, 0), compare); ri--;
        cout << (ri->second - le->second) << "\n";
    }
}

int main()
{
    solve();
    return 0;
}