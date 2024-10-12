#include<bits/stdc++.h>
using namespace std;
void work(){
    string s;
    cin>>s;
    map<char,int> mp;
    for(auto c:s)mp[c]++;
    long long ans=1e18;
    for(auto [c,v]:mp){
        ans=min(ans,(long long)(s.size()-v));
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
}