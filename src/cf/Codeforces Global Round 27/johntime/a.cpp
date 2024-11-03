#include<bits/stdc++.h>
using namespace std;
void work(){
    long long n,m,r,c;
    cin >> n >> m >> r >> c;
    long long ans=0;
    long long front=m*(r-1)+c;
    long long back=n*m-front;
    ans+=back;
    long long trans=n-r;
    ans+=trans*(m-1);
    cout<<ans<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        work();
    }
}