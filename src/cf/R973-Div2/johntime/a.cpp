#include<bits/stdc++.h>
using namespace std;
void work(){
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    int c=min(a,b);
    if(n%c){
        cout<<n/c+1<<'\n';
    }else{
        cout<<n/c<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
}