#include <bits/stdc++.h>
using namespace std;

#define LL long long
int n;

bool check(int x, vector<LL> &a)
{
    priority_queue<LL> even,need;
    LL res = 0;
    for (auto v : a)
    {
        if (v < x)
        {
            need.push(v);
        }
        else
        {
            res++;
            if (v % 2 == 0)
            {
                even.push(v);
            }
        }
    }
    if (res >= x)
        return true;

    while (!even.empty() && !need.empty())
    {
        auto h = even.top(), ne = need.top();
        even.pop();
        need.pop();
        if (h / 2 >= x)
        {   
            if(ne*2 < x)
            {
                need.push(ne*2);
            }
            else
            {
                res++;
            }
            if (h / 4 >= x)
            {
                if((h/2)%2==0)even.push(h / 2);
            }
        }
        else
        {
            break;
        }
    }
    return res >= x;
}

void solve()
{
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid, a))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}