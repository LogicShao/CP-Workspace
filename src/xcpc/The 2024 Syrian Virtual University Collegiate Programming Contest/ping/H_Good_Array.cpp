// Wrong answer on test 8

#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL n;

bool check(LL x, vector<LL> &a)
{
    LL need = 0, sign = n + 1;
    vector<LL> b(n + 1);
    b[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i - 1] < x)
        {
            // b[i] = b[i - 1] + ceil(log2((double)x / a[i - 1]));
            b[i] = b[i - 1];
            LL temp = a[i - 1];
            while (temp < x)
            {
                temp *= 2;
                b[i]++;
            }
        }
        else
        {
            sign = i;
            break;
        }
    }
    if (n - sign + 1 >= x)
        return true;
    need = b[sign - 1] - b[n - x];
    for (int i = sign; i <= n; ++i)
    {
        LL temp = a[i - 1];
        while(temp % 2 == 0)
        {
            temp /= 2;
            if (temp < x)
                break;
            else
                need--;
            if (need <= 0)
                return true;
        }
    }
    return need <= 0;
}

void solve()
{
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

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