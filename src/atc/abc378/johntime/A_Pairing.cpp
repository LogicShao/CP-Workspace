#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a(11);
    for(int i=0;i<4;++i){
        int x;
        cin>>x;
        a[x]++;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        while(a[i]>=2){
            ans+=1;
            a[i]-=2;
        }
    }
    cout<<ans;
}