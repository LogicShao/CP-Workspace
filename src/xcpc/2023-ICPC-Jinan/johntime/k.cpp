#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void work()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 10);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = a[i] - i;
    }
    ll l = 1, r = 1;
    ll ans = 0;
    ll sum1 = 0, sum2 = 0;
    multiset<ll> s1, s2; // 用于维护区间的中位数
    s1.insert(a[1]);
    sum1+=a[1];
    auto balance = [&]()
    {
        while (s1.size() > s2.size())
        {
            s2.insert(*s1.rbegin());
            sum1-=*s1.rbegin();
            sum2+=*s1.rbegin();
            s1.erase(s1.find(*s1.rbegin()));
        }
        while (s2.size() > s1.size())
        {
            s1.insert(*s2.begin());
            sum1+=*s2.begin();
            sum2-=*s2.begin();
            s2.erase(s2.begin());
        }
    };
    while(r<=n){
        balance();
        ll len=r-l+1;
        if(len==0){
            r++;
            s1.insert(a[r]);
            sum1+=a[r];
            continue;
        }
        ll mid=len%2?*s1.rbegin():*s1.rbegin()/2+*s2.begin()/2;
        ll cost=(mid*s1.size()-sum1)+(sum2-mid*s2.size());
        if(cost<=k){
            ans=max(ans,len);
            r++;
            s1.insert(a[r]);
            sum1+=a[r];
        }else{
            if(s1.find(a[l])!=s1.end()){
                s1.erase(s1.find(a[l]));
                sum1-=a[l];
            }else{
                s2.erase(s2.find(a[l]));
                sum2-=a[l];
            }
            l++;
        }
    }
    cout << ans << endl;
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