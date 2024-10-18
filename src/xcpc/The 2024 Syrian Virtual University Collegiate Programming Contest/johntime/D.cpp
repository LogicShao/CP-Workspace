#include <bits/stdc++.h>
using namespace std;
void work()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    if (n == 1)
    {
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0';
    }
    int max1 = -1, max2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max1)
        {
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2)
        {
            max2 = a[i];
        }
    }
    int ans = 2;
    if (max1 == a[n - 1])
        ans--;
    if (max2 == a[0])
        ans--;
    if(max1==a[0]&&max2==a[n-1])ans=min(ans,1);
    cout << ans << ' ';
    sort(a.begin(), a.end());
    swap(a[0], a[n - 2]);
    long long res = 0;
    // for(auto x:a){
    //     cout<<x<<' ';
    // }
    // cout<<endl;
    for (int i = 1; i < n; i++)
    {
        res = a[i - 1] * 10 + a[i] + res;
    }
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
}