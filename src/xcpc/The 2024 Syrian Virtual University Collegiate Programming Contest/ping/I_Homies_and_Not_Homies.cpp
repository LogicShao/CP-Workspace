#include <bits/stdc++.h>
using namespace std;

#define LL long long

void solve()
{
    int n;
    cin >> n;

    LL ans = 0;
    LL temp = 1, cnt = 0;
    while (temp <= n)
    {
        temp *= 2;
        if (temp > n)
            break;

        ans += (1 << cnt) + (1 << (cnt - 1)) * (cnt / 2);
        cnt++;
    }

    int len = cnt + 1;
    n -= temp / 2; n++;
    ans += n;
    temp = 1;
    cnt = 0;
    while (temp < n)
    {
        cnt++;
        if ((len - cnt) % 2 == 0)
        {
            int add = 0;
            int m = n / (1 << (cnt - 1));
            if (m % 2 == 1)
                add += n % (1 << (cnt - 1));
            add += m / 2 * (1 << (cnt - 1));
            ans += add;
        }
        temp *= 2;
    }
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}