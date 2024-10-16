#include<bits/stdc++.h>
using namespace std;
void work(){
    int n,r;
    cin>>n>>r;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans=0,res=0;
    for(auto x:a){
        ans+=(x/2)*2;
        res+=x%2;
        r-=x/2;
    }
    if(res==0){
        cout<<ans<<endl;
        return;
    }else{
        cout<<ans+min(r*2-res,res)<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
}