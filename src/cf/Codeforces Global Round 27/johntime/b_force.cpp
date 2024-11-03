#include<bits/stdc++.h>
using namespace std;
int getw(long long x){
    int ans=0;
    while(x){
        x/=10;
        ans++;
    }
    return ans;
}
bool check(long long x){
    while(x){
        int t=x%10;
        if(t!=3&&t!=6)return 0;
        x/=10;
    }
    return 1;
}
void work(){
    long long a=0;
    vector<int> vis(10,0);
    for(a=0;a<1e9;a++){
        if(!vis[getw(a)]){
            if(a%66==0&&a%33==0&&check(a)){
                cout<<"size: "<<getw(a)<<" "<<a<<endl;
                vis[getw(a)]=1;
            }
        }
    }
}
int main(){
    work();
}