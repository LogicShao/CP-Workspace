#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,maxn=0;
bool flag=0;
bool check(vector<pair<ll,ll>> &a,ll x) {
    ll p1=-1,t1=0,p2=-1,t2=0;
    ll max1=0,max2=0;
    for(int i=1;i<=n;i++) {
        auto [tt,p]=a[i];
        if(p>x) {
            if(p2==-1) {
                p2=p;
                t2=tt;
            }else {
                ll t=tt-t2;
                ll dis=abs(p-p2);
                if(t==0) return false;
                if(dis%t==0) {
                    max2=max(dis/t,max2);
                    p2=p;
                }else {
                    max2=max(dis/t+1,max2);
                    p2=p;
                }
                t2=tt;
            }
        }else {
            if(p1==-1) {
                p1=p;
                t1=tt;
            }else {
                ll t=tt-t1;
                ll dis=abs(p-p1);
                if(t==0) return true;

                if(dis%t==0) {
                    max1=max(dis/t,max1);
                    p1=p;
                }else {
                    max1=max(dis/t+1,max1);
                    p1=p;
                }
            }
            t1=tt;
        }
    }
    if(max1==max2) {
        cout<<max1<<'\n';
        flag=1;
    }
    maxn=max(maxn,max(max1,max2));
    return max1>max2;
}
void work() {
    cin >> n;
    vector<pair<ll, ll> > a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    for(int i=2,cnt=1;i<=n;i++) {
        if(a[i].first==a[i-1].first)cnt++;
        else cnt=0;
        if(cnt>=3) {
            cout<<"-1"<<'\n';
            return;
        }
    }
    ll lb = -1, ub = 1e9+10;
    while (ub - lb > 1&&!flag) {
        ll mid = (lb + ub) / 2;
        if (check(a, mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    if(!flag)cout<<maxn<<'\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        flag=0;
        work();
    }
}

//
// Created by johntimeson on 24-9-28.
//
