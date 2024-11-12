#include<bits/stdc++.h>
using namespace std;
long long lowbit(long long x){
    return x&(-x);
}
long long query(vector<long long> &c,long long x){
    long long ans=0;
    for(long long i=x;i;i-=lowbit(i)){
        ans+=c[i];
    }
    return ans;
}
void add(vector<long long> &c,long long x,long long y){
    for(long long i=x;i<c.size();i+=lowbit(i)){
        c[i]+=y;
    }
}
int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n+10),sum(n+10,0),c(m<<2,0);
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]+a[i])%m;
    }
    long long ans=0,tot=0;
    for(long long i=1;i<=n;i++){
        ans+=sum[i]*i-tot+(query(c,m<<1)-query(c,sum[i]+1))*m;
        tot+=sum[i];
        add(c,sum[i]+1,1);
    }
    cout<<ans;
}