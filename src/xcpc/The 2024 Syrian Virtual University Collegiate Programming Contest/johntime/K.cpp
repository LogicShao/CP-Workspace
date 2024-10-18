#include<bits/stdc++.h>
constexpr int mod=998244353;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string s=*min_element(a.begin()+1,a.end());
    // cout<<s<<endl;
    long long res=0;
    for(int i=0;i<n;i++){
        res=((res*10)%mod+(s[i]-'0'))%mod;    
    }
    res=res%mod;
    cout<<(res*n)%mod<<endl;
}