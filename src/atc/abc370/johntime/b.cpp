#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    long long ans=1;
    for(int i=1;i<=n;i++){
        if(ans>=i)ans=a[ans][i];
        else ans=a[i][ans];
    }
    cout<<ans<<endl;
}