#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> g(n+10,vector<int>(m+10)),vis(n+10,vector<int>(m+10));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            char ch;
            cin>>ch;
            g[i][j]=ch=='.'?0:1;
        }
    }
    int ans=0;
    function<void(int,int,int)> dfs=[&](int x,int y,int c)->void{
        if(x<1||x>n||y<1||y>m||g[x][y]==1||vis[x][y]==1){
            return;
        }
        if(c==k){
            ans++;
            return;
        }
        vis[x][y]=1;
        dfs(x+1,y,c+1);
        dfs(x-1,y,c+1);
        dfs(x,y+1,c+1);
        dfs(x,y-1,c+1);
        vis[x][y]=0;
    };
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(g[i][j]==0){
                dfs(i,j,0);
            }
        }
    }
    cout<<ans<<endl;
}