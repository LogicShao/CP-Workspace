#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
vector<ll> t,d;
bool check(ll w){
    pair<ll,ll> p1={1,1e9},p2={1,1e9};
    for(int i=1;i<=n;i++){
        p1={max(p1.first-(t[i]-t[i-1])*w,1ll),min(p1.second+(t[i]-t[i-1])*w,(ll)1e9)};
        p2={max(p2.first-(t[i]-t[i-1])*w,1ll),min(p2.second+(t[i]-t[i-1])*w,(ll)1e9)};
        if(p1.first<=d[i]&&d[i]<=p1.second){
            if(p2.first<=d[i]&&d[i]<=p2.second){
                p2={min(p1.first,p2.first),max(p1.second,p2.second)};
                p1={d[i],d[i]};
            }else{
                p1={d[i],d[i]};
            }
        }else{
            if(p2.first<=d[i]&&d[i]<=p2.second){
                p2={d[i],d[i]};
            }else{
                return false;
            }
        }
    }
    return true;
}
void work()
{
    cin >> n;
    t.resize(n + 1);
    d.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> d[i];
    }
    t[0]=1;
    d[0]=1;
    ll l=0,r=1e9+1;
    while(l<r){
        ll m=(l+r)/2;
        if(check(m)){
            r=m;
        }else{
            l=m+1;
        }
    }
    if(l==1e9+1){
        cout<<-1<<endl;
        return;
    }
    cout<<l<<endl;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
}