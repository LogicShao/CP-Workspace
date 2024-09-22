#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
	cin>>n;
    vector<ll> x(n+1),p(n+1),c(n+1,0);
	for(ll i=1;i<=n;i++){
        cin>>x[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>p[i];
        c[i]=c[i-1]+p[i];
    }
    ll m;
    cin>>m;
    while(m--){
        ll l,r;
        cin>>l>>r;
        ll l1=lower_bound(x.begin()+1,x.end(),l)-x.begin();
        ll r1=upper_bound(x.begin()+1,x.end(),r)-x.begin();
        cout<<c[r1-1]-c[l1-1]<<endl;
    }
	return 0;
}