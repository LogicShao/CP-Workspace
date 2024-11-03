#include<bits/stdc++.h>
using namespace std;
void work(int n){
    vector<int> a(n);
    iota(a.begin(),a.end(),1);
    int k=0,maxn=0;
    if(n==5)maxn=5;
    if(n==6)maxn=7;
    if(n==7)maxn=7;
    if(n==8)maxn=15;
    if(n==9)maxn=9;
    if(n==10)maxn=15;
    if(n==11)maxn=11;
    vector<int> maxp;
    cout<<"n: "<<n<<endl;
    do{
        for(int i=0;i<n;i++){
            if((i+1)&1)k&=a[i];
            else k|=a[i];
        }
        if(k>=maxn){
            maxn=k;
            maxp=a;
            for(int i=0;i<n;i++){
                cout<<a[i]<<' ';
            }
            cout<<endl;
        }
    }while(next_permutation(a.begin(),a.end()));
    // cout<<n<<": ";
    // for(int i=0;i<n;i++){
    //     cout<<maxp[i]<<' ';
    // }
    // cout<<maxn<<endl;
}
int main(){
    freopen("c_force.txt","w",stdout);
    for(int i=5;i<=11;i++){
        work(i);
    }
}