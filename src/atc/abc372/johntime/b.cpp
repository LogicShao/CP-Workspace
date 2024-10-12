#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll m;
    cin>>m;
    vector<ll> fac3(11);
    fac3[0]=1;
    for(int i=1;i<11;i++)fac3[i]=fac3[i-1]*3;
    ll cnt=0;
    vector<ll> a;
    while(m){
        for(int i=10;i>=0;i--){
            if(m<fac3[i])continue;
            m-=fac3[i];
            cnt++;
            a.push_back(i);
            break;
        }
    }
    cout<<cnt<<'\n';
    for(auto &x:a)cout<<x<<' ';
}