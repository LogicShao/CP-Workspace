#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i])ans++;
    }
    cout<<ans<<'\n';
    for(int i=0;i<n;i++){
        if(t[i]<s[i]){
            s[i]=t[i];
            cout<<s<<'\n';
        }
    }
    for(int i=n;i>=0;i--){
        if(t[i]!=s[i]){
            s[i]=t[i];
            cout<<s<<'\n';
        }
    }
}