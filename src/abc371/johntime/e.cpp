#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> lst(2e5+10,0);
    long long ans=0;
    for(long long i=1;i<=n;i++){
        long long x;
        cin>>x;
        ans+=(i-lst[x])*(n-i+1);
        lst[x]=i;
    }
    cout<<ans;
}
//
// Created by johntimeson on 24-9-22.
//
