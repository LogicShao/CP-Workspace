#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,bool> mp;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x;
        char ch;
        cin>>x>>ch;
        if(ch=='M'){
            if(!mp[x]){
                mp[x]=true;
                cout<<"Yes"<<'\n';
            }else{
                cout<<"No"<<'\n';
            }
        }else{
            cout<<"No"<<'\n';
        }
    }
}