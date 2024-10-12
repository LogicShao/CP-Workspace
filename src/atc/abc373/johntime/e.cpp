#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n+1);
    ll sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<ll> b(n+1);
    b=a;
    sort(b.begin()+1,b.end());
    vector<ll> c(n+1);
    for(ll i=1;i<=n;i++){
        c[i]=c[i-1]+b[i];
    }
    ll ans=0;
    auto check=[&](ll mid,ll id) -> bool{
        ll res = k-c[n]-mid;
        if(n==m)return 1;
        ll x=upper_bound(b.begin()+1,b.end(),a[id]+mid)-b.begin()-1;
        ll y=n-m+1;
        if(n-x>=m)return 0;
        if(b[y]>a[id]) return (x-y+1)*(a[id]+mid+1)-(c[x]-c[y-1])>res;
        else return (x-y+1)*(a[id]+mid+1)-(c[x]-c[y-2]-a[id])>res;
    };
    for(ll i=1;i<=n;i++){
        ll l=0,r=k-c[n]+1;
        while(l<r){
            ll mid=(l+r)/2;
            if(check(mid,i)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        if(l==k-c[n]+1){
            cout<<-1<<' ';
            continue;
        }
        cout<<l<<' ';
    }
}