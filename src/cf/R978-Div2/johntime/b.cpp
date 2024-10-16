#include<bits/stdc++.h>
using namespace std;
void work(){
    long long n,x;
    cin>>n>>x;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum=0;
    long long ans=-1;
    for(auto x:a){
        sum+=x;
        ans=max(ans,x);
    }
    cout<<std::max(ans,(sum+x-1)/x)<<endl;

}
int main(){
    long long t;
    cin>>t;
    while(t--){
        work(); 
    }
}