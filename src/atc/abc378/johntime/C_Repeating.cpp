#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+10);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    map<int,vector<int>> mp;
    for(int i=1;i<=n;++i){
        mp[a[i]].push_back(i);
    }
    for(int i=1;i<=n;++i){
        auto pos=lower_bound(mp[a[i]].begin(),mp[a[i]].end(),i);
        if(pos==mp[a[i]].begin()){
            cout<<-1<<' ';
        }else{
            cout<<*(--pos)<<' ';
        }
    }
}