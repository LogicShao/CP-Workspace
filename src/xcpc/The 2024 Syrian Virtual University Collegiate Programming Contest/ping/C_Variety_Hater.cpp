// Wrong answer on test 3

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PLL pair<LL, LL>

void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    map<LL, LL> b;
    b.insert(make_pair(a[0], 1));
    for (int i = 1; i < n; ++i)
    {
        if (b.count(a[i]) > 0)
            b[a[i]]++;
        else
            b.insert(make_pair(a[i], 1));
    }

    priority_queue<PLL, vector<PLL>, greater<PLL>> q;
    for (auto i = next(b.begin()); i != b.end(); i++)
    {
        
        q.push(make_pair((i->first - prev(i)->first) * i->second, -i->first));
        q.push(make_pair((i->first - prev(i)->first) * prev(i)->second, i->first));
    }

    LL ans = b.size();
    while (k && !q.empty())
    {
        if (k < q.top().first)
            break;
        
        int temp;
        auto i = b.find(abs( q.top().second ));
        if (q.top().second < 0)
        {
            if (q.top().first != (i->first - prev(i)->first) * i->second)
            {
                q.pop();
                continue;
            }
            prev(i)->second += i->second;
            i++;
            b.erase(prev(i)->first);
            q.pop();
            ans--;

            q.push(make_pair((i->first - prev(i)->first) * i->second, -i->first));
            q.push(make_pair((i->first - prev(i)->first) * prev(i)->second, i->first));

            i--;
            if (i != b.begin())
            {
                q.push(make_pair((i->first - prev(i)->first) * i->second, -i->first));
                q.push(make_pair((i->first - prev(i)->first) * prev(i)->second, i->first));
            }
        }
        else
        {
            if (q.top().first != (i->first - prev(i)->first) * i->second)
            {
                q.pop();
                continue;
            }
            i->second += prev(i)->second;
            b.erase(prev(i)->first);
            q.pop();
            ans--;

            if (i != b.begin())
            {
                q.push(make_pair((i->first - prev(i)->first) * i->second, -i->first));
                q.push(make_pair((i->first - prev(i)->first) * prev(i)->second, i->first));
            }
            
            i++;
            q.push(make_pair((i->first - prev(i)->first) * i->second, -i->first));
            q.push(make_pair((i->first - prev(i)->first) * prev(i)->second, i->first));
        }
    }
    cout << ans << endl;
    // for (auto i : b)
    //     cout << i.first << " " << i.second << " | ";
    // cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}