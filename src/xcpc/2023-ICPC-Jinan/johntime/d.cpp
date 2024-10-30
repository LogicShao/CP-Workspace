#include<bits/stdc++.h>
using namespace std;
int f(int x){
    int res=-1;
    while(x){
        res=max(res,x%10);
        x/=10;
    }
    return res;
}
void work(){
    int a,b,l,r;
    cin>>a>>b>>l>>r;
    int ans=-1;
    for(int i=a;i<=min(a+10,b);i++){
        for(int j=l;j<=min(l+10,r);j++){
            ans=max(ans,f(i+j));
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)work();
}