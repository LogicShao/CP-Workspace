#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void work(){
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n-2;i++){
        a[n-1]-=a[i];
    }
    cout<<a[n]-a[n-1]<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
}