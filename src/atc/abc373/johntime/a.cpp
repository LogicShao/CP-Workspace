#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    for(int i=1;i<=12;i++){
        string s;
        cin>>s;
        if(s.length()==i){
            ans++;
        }
    }
    cout<<ans;
}