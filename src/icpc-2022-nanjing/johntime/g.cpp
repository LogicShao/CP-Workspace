#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll __gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
void work()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;
    ll sumc = 0, sum = 0;
    for (auto &ai : a)
    {
        if (ai == 0)
            sumc++;
        sum += ai;
        if (sumc + sum < 0)
        {
            cout << "-1\n";
            return;
        }
    }
    ll q = 1, p = 1;
    for (auto &ai : a)
    {
        if (ai == 0)
        {
            if (sum >= sumc)
            {
                p--;
                sum--;
                sumc--;
            }
            else
            {
                q++, p++;
                sum++;
                sumc--;
            }
        }
        if (ai == 1)
        {
            q++, p++;
        }
        if (ai == -1)
        {
            p--;
        }
    }
    ll b = __gcd(p, q);
    cout << q / b << ' ' << p / b << '\n';
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        work();
    }
}