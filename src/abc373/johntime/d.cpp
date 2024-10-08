#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n,m;
    cin>>n>>m;
    struct edge{
        ll v,w;
    };
    vector<vector<edge>> g(n+1);
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,-w});
    }
    queue<ll> q;
    vector<bool> vis(n+1,false);
    vector<ll> ans(n+1,0);
    auto bfs=[&](){
        while(!q.empty()){
            ll u=q.front();
            q.pop();
            vis[u]=true;
            for(auto [v,w]:g[u]){
                ans[v]=ans[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        q.push(i);
        vis[i]=true;
        bfs();
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}