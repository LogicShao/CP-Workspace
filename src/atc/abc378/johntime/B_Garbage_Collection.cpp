#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin>>N;
    vector<long long> q(110),r(110);
    for(long long i=1;i<=N;++i){
        cin>>q[i]>>r[i];
    }
    long long Q;
    cin>>Q;
    for(long long i=1;i<=Q;++i){
        long long t,d;
        cin>>t>>d;
        auto round=q[t],last=r[t];
        long long lb=0,ub=1e9+10;
        while(lb<ub){
            long long mid=(lb+ub)/2;
            if(round*mid+last>=d){
                ub=mid;
            }else{
                lb=mid+1;
            }
        }
        cout<<round*lb+last<<endl;
    }
}