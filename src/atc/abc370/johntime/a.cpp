#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    cin>>l>>r;
    if(l==r){
        cout<<"Invalid"<<endl;
        return 0;
    }
    if(l==1){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(r==1){
        cout<<"No"<<endl;
        return 0;
    }
}