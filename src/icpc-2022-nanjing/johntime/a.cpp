#include<bits/stdc++.h>
using namespace std;
void add(vector<vector<int>> &f,int x1,int y1,int x2,int y2){
    f[x1][y1]++;
    f[x2+1][y1]--;
    f[x1][y2+1]--;
    f[x2+1][y2+1]++;
}
void work(){
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    int u=1,d=m,l=1,r=n;
    int nowx=0,nowy=0;
    for(auto &c:s){
        if(c=='U'){
            nowy++;
        }
        if(c=='D'){
            nowy--;
        }
        if(c=='L'){
            nowx++;
        }
        if(c=='R'){
            nowx--;
        }
        u=max(u,nowy+1);
        d=min(d,nowy+m);
        l=max(l,nowx+1);
        r=min(r,nowx+n);
    }
    if(u>d||l>r){
        if(k==0){
            cout<<n*m<<'\n';
            return;
        }else{
            cout<<"0\n";
            return;
        }
    }
    if((d-u+1)*(r-l+1)<k){
        cout<<"0\n";
        return;
    }
    int rest = (d-u+1)*(r-l+1)-k;
    vector<vector<int>> f(n+1,vector<int>(m+1,0));
    

}
int main(){
    int t;
    cin>>t;
    while(t--){
        work();
    }
}