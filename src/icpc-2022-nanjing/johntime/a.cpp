#include<bits/stdc++.h>
using namespace std;
constexpr int D = 100;
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
    int u=1,d=n,l=1,r=m;
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
        d=min(d,nowy+n);
        l=max(l,nowx+1);
        r=min(r,nowx+m);
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
    vector<vector<int>> f(D*2+n,vector<int>(D*2+m,0));
    vector<vector<int>> vis(D*2+n,vector<int>(D*2+m,0));
    add(f,u+D,l+D,d+D,r+D);
    vis[u+D][l+D]=1;
    for(auto &c:s){
        if(c=='U'){
            u--,d--;
        }
        if(c=='D'){
            u++,d++;
        }
        if(c=='L'){
            l--,r--;
        }
        if(c=='R'){
            l++,r++;
        }
        if(!vis[u+D][l+D]){
            add(f,u+D,l+D,d+D,r+D);
        }
        vis[u+D][l+D]=1;
    }
    for(int i=D+1;i<=D+n;i++){
        for(int j=D+1;j<=D+m;j++){
            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f[i+D][j+D]==rest){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        work();
    }
}